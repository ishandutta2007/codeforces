#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 2010, LOG=22;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a, b-1)%mod;
	return powmod(a*a%mod, b>>1);
}
ll F[200000], I[200000];
ll C(ll n, ll r){
	if (r<0 || r>n || n<0) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

ll n, m, k, s, v, x, y, t, a, b, ans, cnt;
pll A[MAXN];
ll dp[MAXN][LOG];

ll calc(ll i, ll j){ return C(A[j].first-A[i].first+A[j].second-A[i].second, A[j].first-A[i].first);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<200000; i++) F[i]=F[i-1]*i%mod;
	I[199999]=powmod(F[199999], mod-2);
	for (int i=199999; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>m>>k>>s;
	for (int i=1; i<=k; i++) cin>>A[i].first>>A[i].second;
	A[0]={1, 1};
	sort(A, A+k+1);
	A[++k]={n, m};
	for (int i=0; i<=k; i++) for (int j=0; j<LOG; j++){
		dp[i][j]=calc(0, i);
		for (int x=0; x<i; x++) dp[i][j]=(dp[i][j]-dp[x][j]*calc(x, i))%mod;
		for (int jj=0; jj<j; jj++) dp[i][j]=(dp[i][j]-dp[i][jj])%mod;
	}
	for (int i=1; i<LOG; i++){
		ans=(ans+dp[k][i]*s)%mod;
		cnt=(cnt+dp[k][i])%mod;
		s=(s+1)/2;
	}

	cnt=calc(0, k)-cnt;
	ans=(ans+cnt+2*mod)%mod;	
	cout<<ans*powmod(calc(0, k), mod-2)%mod<<'\n';
	
	return 0;
}