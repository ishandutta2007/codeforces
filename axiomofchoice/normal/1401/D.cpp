#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
vector<int> a[N],w,v;
int sz[N],n;
void dfs(int x,int fa=-1){
	sz[x]=1;
	for(auto p:a[x])if(p!=fa){
		dfs(p,x);
		v<<(sz[p]*(n-sz[p]));
		sz[x]+=sz[p];
	}
}
void Solve(){
	n=read();
	repeat(i,1,n+1)a[i].clear(); w.clear(); v.clear();
	repeat(i,0,n-1){
		int x=read(),y=read();
		a[x]<<y; a[y]<<x;
	}
	int m=read();
	repeat(i,0,m)w<<read();
	repeat(i,m,n-1)w<<1ll;
	dfs(1);
	ll ans=0;
	sort(w.begin(),w.end());
	while((int)w.size()>n-1){
		int a=w.back(); w.pop_back();
		int b=w.back(); w.pop_back();
		w<<(a*b%mod);
	}
	sort(v.begin(),v.end());
	repeat(i,0,n-1)ans+=v[i]%mod*w[i]%mod;
	ans%=mod;
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}