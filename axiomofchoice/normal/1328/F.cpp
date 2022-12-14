#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=[]{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
#endif
const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int a[N];
map<int,int> m,m2;
signed main(){
	int n=read(),k=read();
	repeat(i,0,n)a[i]=read();
	sort(a,a+n);
	repeat(i,0,n){
		m[a[i]]++;
		if(!m.count(a[i]-1))m[a[i]-1]=0;
		if(!m.count(a[i]+1))m[a[i]+1]=0;
	}
	for(auto i:m)if(i.se>=k)cout<<0,exit(0);
	m2=m;
	
	int mid=a[(n-1)/2];
	ll nowl=0,nowr=0;
	repeat(i,0,n){
		if(a[i]<mid){
			nowl+=mid-a[i];
		}
		if(a[i]>mid){
			nowr+=a[i]-mid;
		}
	}
	
	ll now0=nowl+nowr-(n-k);
	
	ll now1=0;
	for(auto i=m.begin();i!=m.end();i++){
		if(i->se>=k)break;
		auto nxt=i; nxt++;
		if(nxt->se+i->se>=k){
			now1+=1ll*abs(nxt->fi-i->fi)*(k-nxt->se);
			break;
		}
		nxt->se+=i->se;
		now1+=1ll*abs(nxt->fi-i->fi)*(i->se);
	}
	
	m=m2;
	
	ll now2=0;
	for(auto i=m.rbegin();i!=m.rend();i++){
		if(i->se>=k)break;
		auto nxt=i; nxt++;
		if(nxt->se+i->se>=k){
			now2+=1ll*abs(nxt->fi-i->fi)*(k-nxt->se);
			break;
		}
		nxt->se+=i->se;
		now2+=1ll*abs(nxt->fi-i->fi)*(i->se);
	}
	cout<<min(now0,min(now1,now2));
	return 0;
}