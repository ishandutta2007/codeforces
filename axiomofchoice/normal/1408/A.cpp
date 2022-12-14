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
const ll mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N][3];
void Solve(){
	int n=read();
	repeat(j,0,3)
	repeat(i,0,n)
		a[i][j]=read();
	repeat(i,0,n-1)
	if(a[i][0]==a[i+1][0])
		swap(a[i+1][0],a[i+1][1]);
	if(a[n-1][0]==a[0][0])
		swap(a[n-1][0],a[n-1][2]);
	if(a[n-1][0]==a[n-2][0])
		swap(a[n-1][0],a[n-1][1]);
	repeat(i,0,n)
		printf("%lld ",a[i][0]);
	puts(""); 
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}