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
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int n,k; string s;
map<char,int> mp;
int work(int k){
	int l=1,r=2001;
	while(l<=r){
		int m=(l+r)/2;
		int cnt=0;
		for(auto i:mp)cnt+=i.se/m;
		if(cnt<k)r=m-1;
		else l=m+1;
	}
	return r*k;
}
signed main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>k; 
		cin>>s; mp.clear(); for(auto i:s)mp[i]++;
		int ans=0;
		for(auto i:mp)ans=max(ans,i.se);
		for(int i=1;i<=k;i++)
		if(k%i==0)
			ans=max(ans,work(i));
		cout<<ans<<endl;
	}
	return 0;
}