#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100100;
namespace FIFO{
char buf[1<<23],*p1=buf,*p2=buf;
#ifndef Troverld
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#else
#define gc() getchar()
#endif
template<typename T>void read(T&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
template<typename T>void print(T x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
int n,m,dep[N],fa[N],son[N],top[N],sz[N];
struct frac{
	ll x,y;
	void print(){printf("(%lld/%lld)",x,y);}
	void operator~(){if(y<0)y=-y,x=-x;ll gcd=__gcd(abs(x),y);x/=gcd,y/=gcd;}
	frac(ll X=0,ll Y=1){x=X,y=Y;~(*this);}
	friend frac operator+(const frac&u,const frac&v){return frac(u.x*v.y+u.y*v.x,u.y*v.y);}
	friend frac operator-(const frac&u,const frac&v){return frac(u.x*v.y-u.y*v.x,u.y*v.y);}
	friend frac operator*(const frac&u,const frac&v){return frac(u.x*v.x,u.y*v.y);}
	friend frac operator/(const frac&u,const frac&v){return frac(u.x*v.y,u.y*v.x);}
	friend bool operator<(const frac&u,const frac&v){return u.x*v.y<u.y*v.x;}
	friend bool operator==(const frac&u,const frac&v){return u.x*v.y==u.y*v.x;}
	friend bool operator<=(const frac&u,const frac&v){return u.x*v.y<=u.y*v.x;}
	frac operator-()const{return frac(-x,y);}
	double operator()()const{return 1.0*x/y;}
	void rd(){read(x),y=1;}
}T,res(0x3f3f3f3f);
struct Line{
	frac k,b;Line(frac K,frac B){k=K,b=B;}
	frac operator()(frac t)const{return k*t+b;}
	void print(){k.print(),printf("t+"),b.print();}
	friend bool operator<(const Line&u,const Line&v){return u(T)<v(T);}
};
multiset<frac>s;
struct Scan{
	frac tim;Line l;bool tp;
	Scan(frac _tm,Line _ln,bool _tp):tim(_tm),l(_ln),tp(_tp){}
	friend bool operator<(const Scan&u,const Scan&v){return u.tim==v.tim?u.tp<v.tp:u.tim<v.tim;}
};
multiset<Line>t;
vector<Scan>u[N];
vector<int>v[N];
void dfs1(int x){
	sz[x]=1;
	for(auto y:v[x])if(y!=fa[x]){
		dep[y]=dep[fa[y]=x]+1,dfs1(y),sz[x]+=sz[y];
		if(sz[son[x]]<sz[y])son[x]=y;
	}
}
void dfs2(int x){
	if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y!=fa[x]&&y!=son[x])dfs2(y);
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void insert(){
	int x,y,z;frac V;
	T.rd(),V.rd(),read(x),read(y),z=LCA(x,y),T=T+(dep[x]-dep[z])/V;
	Line p(-V,dep[z]+T*V),q(V,dep[z]-T*V);
	while(top[x]!=top[y])if(dep[top[x]]>dep[top[y]]){
		u[top[x]].emplace_back(T-(dep[x]-dep[z])/V,p,false);
		u[top[x]].emplace_back(T-(dep[fa[top[x]]]-dep[z])/V,p,true);
		x=fa[top[x]];
	}else{
		u[top[y]].emplace_back(T+(dep[fa[top[y]]]-dep[z])/V,q,false);
		u[top[y]].emplace_back(T+(dep[y]-dep[z])/V,q,true);
		y=fa[top[y]];
	}
	if(x==z){
		u[top[z]].emplace_back(T,q,false);
		u[top[z]].emplace_back(T+(dep[y]-dep[z])/V,q,true);
	}else{
		u[top[z]].emplace_back(T-(dep[x]-dep[z])/V,p,false);
		u[top[z]].emplace_back(T,p,true);
	}
}
void work(const Line&u,const Line&v,bool tp){
	if(u.k==v.k){if(u.b==v.b){if(tp)s.erase(s.find(T));else s.insert(T);}return;}
	frac S=(u.b-v.b)/(v.k-u.k);
	if(S<T)return;if(tp)s.erase(s.find(S));else s.insert(S);
}
void func(int id){
//	printf("%d:\n",id);
	sort(u[id].begin(),u[id].end());
	s.clear(),t.clear();
//	puts("QWQ");
	for(auto x:u[id]){
//		x.tim.print(),x.l.print(),printf("|%d\n",x.tp);
		T=x.tim;
		if(!s.empty()&&*s.begin()<=T){res=min(res,*s.begin());return;}
		if(x.tp){
			auto it=t.find(x.l);
			it=t.erase(it);
			if(it!=t.begin()&&it!=t.end()){
				Line q=*it,p=*--it;
				work(p,x.l,true),work(x.l,q,true);
				work(p,q,false);
			}else if(it!=t.begin())work(*--it,x.l,true);
			else if(it!=t.end())work(x.l,*it,true);
		}else{
			auto it=t.lower_bound(x.l);
			if(it!=t.begin()&&it!=t.end()){
				Line q=*it,p=*--it;
				work(p,q,true);
				work(p,x.l,false),work(x.l,q,false);
			}else if(it!=t.begin())work(*--it,x.l,false);
			else if(it!=t.end())work(x.l,*it,false);
			t.insert(x.l);
		}
		if(!s.empty()&&*s.begin()<=T){res=min(res,*s.begin());return;}
	}
}
int main(){
	read(n),read(m);
	for(int i=1,x,y;i<n;i++)read(x),read(y),v[x].push_back(y),v[y].push_back(x);
	dfs1(1),dfs2(1);
	for(int i=1;i<=m;i++)insert();
	for(int i=1;i<=n;i++)if(top[i]==i)func(i);
	if(res.x==0x3f3f3f3f)puts("-1");else printf("%lf\n",res());
	return 0;
}