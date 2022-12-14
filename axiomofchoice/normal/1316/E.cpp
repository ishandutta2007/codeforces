#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
#define inline __inline __attribute__((always_inline))
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;}
typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=100010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
vector<int> a[N];
int n,p,kk,x;
ll dp[N][128];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>p>>kk;
	repeat(i,1,n+1)cin>>x,a[i].push_back(x);
	repeat(i,1,n+1)
	repeat(j,1,p+1)cin>>x,a[i].push_back(x);
	sort(a+1,a+n+1,greater< vector<int> >());
	repeat(j,0,(1<<p))
		dp[0][j]=-INF;
	dp[0][0]=0;
	repeat(i,1,n+1)
	repeat(j,0,(1<<p)){
		ll &x=dp[i][j]=-INF;
		if(j)
		repeat(k,0,p)
		if(j&(1<<k))
		//if(dp[i-1][j^(1<<k)])
			x=max(x,dp[i-1][j^(1<<k)]+a[i][k+1]);
		if(kk-i+__builtin_popcountll(j)>=0)
			x=max(x,dp[i-1][j]+a[i][0]);
		else
			x=max(x,dp[i-1][j]);
	}
	//repeat(i,1,n+1)
	//repeat(j,0,(1<<p))
		//cout<<dp[i][j]<<" \n"[j==(1<<p)-1];
	cout<<dp[n][(1<<p)-1]<<endl;
	return 0;
}