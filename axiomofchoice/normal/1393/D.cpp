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
const int N=2010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T>void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
char s[N][N]; int dp[N][N];
void Solve(){
	int n=read(),m=read();
	repeat(i,1,n+1)scanf("%s",s[i]+1);
	repeat(i,1,n+1)
	repeat(j,1,m+1)
		dp[i][j]=1;
	repeat(i,1,n+1)
	repeat(j,1,m+1)
	if(s[i][j]==s[i-1][j] && s[i][j]==s[i-2][j]
	&& s[i][j]==s[i-1][j-1] && s[i][j]==s[i-1][j+1])
		dp[i][j]=min({dp[i-2][j],dp[i-1][j-1],dp[i-1][j+1]})+1;
	ll ans=0;
	repeat(i,1,n+1)
	repeat(j,1,m+1)
		ans+=dp[i][j];
	//repeat(i,1,n+1)orzarr(dp[i]+1,m);
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}