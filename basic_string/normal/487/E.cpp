#include<bits/stdc++.h>
using namespace std;
char _[999999],*U,*V;
#define I (U==V&&(V=(U=_)+fread(_,1,999991,stdin),U==V)?0:*U++)
template<class T>bool in(T&x){char c=I;bool f=0;for(x=0;c<48||c>57;c=I)if(c==45)f=1;else if(!c)return 0;for(;c>47&&c<58;c=I)x=x*10+c-48;if(f)x=-x;return 1;}
char O_[999999],*OU=O_,*OV=OU+999991,OS[21],*OT=OS;
#define F fwrite(O_,1,OU-O_,stdout)
#define O(x) (*(OU=(OU==OV?(F,O_):OU))++=(x))
template<class T>void out(T x){if(x<0)O(45),x=-x;for(;*OT++=x%10+48,x/=10;);for(;OT!=OS;O(*--OT));O(10);}
enum{N=100009,M=N*2,O=N*4};
int n,m,q,c,w[N];
struct H{
	priority_queue<int,vector<int>,greater<int>>a,d;
	void add(int v){a.push(v);}
	void del(int v){d.push(v);}
	int top(){while(d.size()&&a.top()==d.top())a.pop(),d.pop();return a.top();}
}h[M];
namespace T{
int f[M],sz[M],qz[M],tp[M],ftp[M],p[M],ip[M],id,sn[M],fa[O],s[O],lc[O],rc[O],d[O];
basic_string<int>g[M];
void add(int x,int y){g[x]+=y,f[y]=x;}
void qry(int x,int y){
	int ans=2e9,z;
	for(x=p[x],y=p[y];tp[x]^tp[y];x=z){
		if(d[ftp[x]]<d[ftp[y]])swap(x,y);
		for(ans=min(ans,s[x]);(z=fa[x])>c;x=z)if(x==rc[z])ans=min(ans,s[lc[z]]);
	}
	if(x>y)swap(x,y);
	if(ip[x]>n)ans=min(ans,w[f[ip[x]]]);
	for(ans=min(ans,min(s[x],s[y]));x^y;)if(d[x]>d[y]){
		if(x==lc[z=fa[x]]&&z!=y)ans=min(ans,s[rc[z]]);
		x=z;
	}else{
		if(y==rc[z=fa[y]]&&lc[z]!=x)ans=min(ans,s[lc[z]]);
		y=z;
	}
	out(ans);
}
void mdf(int x,int v){for(s[x=p[x]]=v;fa[x]>c;s[x]=min(s[lc[x]],s[rc[x]]))x=fa[x];}
void upd(int x,int v){
	if(mdf(x,v),f[x]>n){
		int a=h[f[x]].top(),b;
		if(h[f[x]].del(w[x]),h[f[x]].add(v),b=h[f[x]].top(),a^b)mdf(f[x],b);
	}w[x]=v;
}
void dfs(int x){
	sz[x]=1;
	for(int o:g[x])if(dfs(o),sz[x]+=sz[o],sz[o]>sz[sn[x]])sn[x]=o;
}
void dfs(int x,int y){
	if(p[x]=++id,tp[id]=p[y],ftp[id]=p[f[y]],ip[id]=x,qz[id]=sz[x]-sz[sn[x]],sn[x])dfs(sn[x],y);
	for(int o:g[x])if(o^sn[x])dfs(o,o);
}
int bd(int l,int r){
	if(l==r)return s[l]=(ip[l]>n?h[ip[l]].top():w[ip[l]]),l;
	int i,x=++id,w=0,o=0;
	for(i=l;i<=r;++i)w+=qz[i];
	for(i=l;i<=r;++i)if(o+=qz[i],o*2>w&&i>l)return lc[x]=bd(l,i-1),rc[x]=bd(i,r),fa[lc[x]]=fa[rc[x]]=x,s[x]=min(s[lc[x]],s[rc[x]]),x;
	return 0;
}
int bd(int x){
	int i,j=0;
	for(i=x;i;j=i,i=sn[i])for(int o:g[i])if(o^sn[i])fa[bd(o)]=p[i];
	return bd(p[x],p[j]);
}
void getd(int x){
	if(d[x])return;
	getd(fa[x]),d[x]=d[fa[x]]+1;
}
void wk(){
	for(int i=2;i<=n;++i)h[f[i]].add(w[i]);
	dfs(1),dfs(1,1),bd(1),d[0]=1;
	for(int i=1;i<=c;++i)getd(i);
}
}
namespace G{
basic_string<int>g[N];
int p[N],l[N],id,st[N],tp;
void tar(int x){
	p[x]=l[x]=++id,st[++tp]=x;
	for(int o:g[x])if(!p[o]){
		if(tar(o),l[x]=min(l[x],l[o]),l[o]==p[x])for(T::add(x,++c);T::add(c,st[tp]),st[tp--]^o;);
	}else l[x]=min(l[x],p[o]);
}
}
int main(){
	int i,j;
	char k;
	for(in(n),in(m),in(q),i=1;i<=n;++i)in(w[i]);
	while(m--)in(i),in(j),G::g[i]+=j,G::g[j]+=i;
	c=n,G::tar(1),T::wk();
	while(q--)if(k=I,in(i),in(j),k=='A')T::qry(i,j);else T::upd(i,j);F;
}