#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=500010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
vector<int> a[N];
struct node{int t,p;}w[N];
int lab[N];
int n,m;
vector<int> v;
int mex(int x){//orz(x);
	v.clear();
	for(auto p:a[x])
	if(lab[p])
		v.push_back(lab[p]);
	sort(v.begin(),v.end());
	unique(v.begin(),v.end());
	repeat(i,0,v.size())
	if(v[i]!=i+1)
		return i+1;
	return v.size()+1;
}
signed main(){
	cin>>n>>m;
	while(m--){
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	repeat(i,0,n){
		cin>>w[i].t;
		w[i].p=i+1;
	}
	sort(w,w+n,[](node a,node b){return a.t<b.t;});
	repeat(i,0,n){
		int t=mex(w[i].p);
		if(t!=w[i].t)
			cout<<-1<<endl,exit(0);
		lab[w[i].p]=w[i].t;
	}
	repeat(i,0,n)cout<<w[i].p<<' ';
	return 0;
}