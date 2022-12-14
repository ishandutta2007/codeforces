#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
//#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N]; char s[N];
int dp[N][2][2][2][2];
void Solve(){
	int n=read();
	scanf("%s",s);
	repeat(i,0,n)a[i]=s[i]=='R';
	repeat(i,0,n)
	repeat(i1,0,2)
	repeat(i2,0,2)
	repeat(k1,0,2)
	repeat(k2,0,2)
		dp[i][i1][i2][k1][k2]=inf;
	repeat(i1,0,2)
	repeat(i2,0,2){
		dp[1][i1][i2][i1][i2]=(a[0]!=i1)+(a[1]!=i2);
	}
	repeat(i,2,n)
	repeat(i1,0,2)
	repeat(i2,0,2)
	repeat(k1,0,2)
	repeat(k2,0,2)
	repeat(k3,0,2)
	if(!(k1==k2 && k2==k3)){
		dp[i][i1][i2][k2][k3]=min(dp[i][i1][i2][k2][k3],
			dp[i-1][i1][i2][k1][k2]+(a[i]!=k3));
	}
	ll ans=inf;
	repeat(i1,0,2)
	repeat(i2,0,2)
	repeat(k1,0,2)
	repeat(k2,0,2){
		if(!(k1==k2 && k1==i1))
		if(!(k2==i1 && k2==i2))
			ans=min(ans,dp[n-1][i1][i2][k1][k2]);
	}
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}