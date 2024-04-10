#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
int a[20][20];
char A[N],B[N];
void Solve(){
	int n=read();
	scanf("%s%s",A,B); mst(a,0);
	repeat(i,0,n){
		if(A[i]>B[i]){
			puts("-1");
			return;
		}
		a[A[i]-'a'][B[i]-'a']++;
	}
	n=20; int ans=0;
	repeat(i,0,n-1){
		int t=inf;
		repeat(j,i+1,n)
		if(a[i][j]){
			t=min(t,j);
		}
		if(t!=inf){
			ans++;
			repeat(j,i+1,n)
				a[t][j]+=a[i][j];
		}
	}
	printf("%d\n",ans);
}
signed main(){
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}