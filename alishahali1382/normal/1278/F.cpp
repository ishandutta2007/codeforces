#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 998244353;
const int MAXN = 5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][MAXN];
ll F[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	ll res=1;
	for (ll i=n; i>n-r; i--) res=res*i%mod;
	res=res*powmod(F[r], mod-2)%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0][0]=1;
	for (int i=1; i<MAXN; i++) for (int j=1; j<=i; j++) dp[i][j]=(dp[i-1][j-1] + dp[i-1][j]*j)%mod;
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	cin>>n>>m>>k;
	ll M=powmod(m, mod-2);
	ll tmp=1;
	for (int i=1; i<=k; i++){
		tmp=tmp*M%mod;
		ans+=((dp[k][i]*F[i]%mod)*tmp%mod)*C(n, i)%mod;
	}
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}