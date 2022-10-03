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
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int color[MAXN];
ll dp[MAXN][2];
vector<int> child[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x){ return powmod(x, mod-2);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n; i++) cin>>x, child[x+1].pb(i);
	for (int i=1; i<=n; i++) cin>>color[i];
	for (int i=n; i; i--){
		if (color[i]){
			dp[i][1]=1;
			for (int j:child[i]) dp[i][1]=dp[i][1]*(dp[j][0]+dp[j][1])%mod;
		}
		else{
			ll val=1, tmp=0;
			for (int j:child[i]) val=val*(dp[j][0]+dp[j][1])%mod;
			dp[i][0]=val;
			for (int j:child[i]) tmp=(tmp+(val*inv(dp[j][0]+dp[j][1])%mod)*dp[j][1])%mod;
			dp[i][1]=tmp;
		}
	}
	
	cout<<dp[1][1]<<'\n';
	
	return 0;
}