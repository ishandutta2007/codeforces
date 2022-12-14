#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct vec{
	lf x,y; vec(){} vec(lf x,lf y):x(x),y(y){}
	vec operator-(const vec &b){return vec(x-b.x,y-b.y);}
	vec operator+(const vec &b){return vec(x+b.x,y+b.y);}
	vec operator*(lf k){return vec(k*x,k*y);}
	lf len(){return hypot(x,y);}
	lf sqr(){return x*x+y*y;}
	vec trunc(lf k=1){return *this*(k/len());}
	vec rotate(double th){lf c=cos(th),s=sin(th); return vec(x*c-y*s,x*s+y*c);}
	vec left(){return vec(-y,x).trunc();}
	lf theta(){return atan2(y,x);}
	friend lf cross(vec a,vec b){return a.x*b.y-a.y*b.x;};
	friend lf cross(vec a,vec b,vec c){return cross(a-c,b-c);}
	friend lf dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
	friend vec trans(vec p,vec a,vec b){
		swap(a.y,b.x);
		return vec(dot(a,p),dot(b,p));
	}
	friend vec arctrans(vec p,vec a,vec b){
		lf t=cross(a,b);
		return vec(-cross(b,p)/t,cross(a,p)/t);
	}
	void output()const{printf("%.12f %.12f\n",x,y);}
	bool operator<(vec b)const{return 0;}
};
multiset<pair<lf,vec>> st; vec c;
typedef multiset<pair<lf,vec>>::iterator ptr;
void push(vec v){
	st.insert({v.theta(),v});
}
void dec(ptr &p){if(p==st.begin())p=st.end(); --p;}
void inc(ptr &p){++p; if(p==st.end())p=st.begin();}
ptr find(vec v){
	auto p=st.lower_bound({v.theta(),v}); dec(p);
	return p;
}
const lf eps=1e-7;
bool out(vec v){
	v=v-c;
	auto l=find(v),r=l; inc(r);
	return cross(l->se,r->se,v)<-eps;
}
void init(vec v1,vec v2,vec v3){
	st.clear();
	c=(v1+v2+v3)*(1.0/3);
	push(v1-c); push(v2-c); push(v3-c);
}
void add(vec v){
	if(!out(v))return;
	v=v-c;
	auto l=find(v),r=l; inc(r);
	auto l2=l; dec(l2);
	while(cross(l->se,l2->se,v)>0){
		dec(l),dec(l2);
	}
	auto r2=r; inc(r2);
	while(cross(r->se,r2->se,v)<0){
		inc(r),inc(r2);
	}
	inc(l);
	if(*l<=*r)st.erase(l,r);
	else st.erase(l,st.end()),st.erase(st.begin(),r);
	st.insert({v.theta(),v});
} 
void Solve(){
	int q=read(); q-=3;
	{
		int x,y; 
		read(),x=read(),y=read(); vec v1(x,y);
		read(),x=read(),y=read(); vec v2(x,y);
		read(),x=read(),y=read(); vec v3(x,y);
		init(v1,v2,v3); 
	}
	while(q--){
		int op=read(),x=read(),y=read();
		vec v(x,y);
		if(op==1){
			add(v);
		}
		else{
			cout<<(!out(v)?"YES":"NO")<<endl;
		}
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}