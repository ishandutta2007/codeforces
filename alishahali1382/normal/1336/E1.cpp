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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define get(x, y) (((x)>>(y))&1)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 998244353;
const int MAXN=200010, N=35, M=15;

ll n, m, k, u, v, x, y, t, a, b, tav2=1;
ll ans[MAXN];
ll G[N+1], sz=0;
bool ok[N+1];
ll dp[N+1][N+1][1<<M];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>x;
		for (int j=0; j<sz; j++) if (G[j]&-G[j]&x) x^=G[j];
		if (!x){
			tav2=tav2*2%mod;
			continue ;
		}
		
		for (int j=0; j<sz; j++) if (x&-x&G[j]) G[j]^=x;
		
		G[sz++]=x;
		ok[__builtin_ctzll(x)]=1;
	}
	if (m-sz>M){
		for (int mask=0; mask<(1<<sz); mask++){
			ll x=0;
			for (int i=0; i<sz; i++) if (get(mask, i)) x^=G[i];
			ans[__builtin_popcountll(x)]++;
		}
		for (int i=0; i<=m; i++) cout<<ans[i]*tav2%mod<<' ';
		cout<<'\n';
		return 0;
	}
	//for (int i=0; i<sz; i++) debug(G[i])
	
	for (int i=0; i<m-sz; i++) if (ok[i]){
		for (int j=m-1; j>i; j--) if (!ok[j]){
			swap(ok[i], ok[j]);
			for (int k=0; k<sz; k++){
				ll a=get(G[k], i), b=get(G[k], j);
				G[k]&=-1ll-(1ll<<i);
				G[k]&=-1ll-(1ll<<j);
				G[k]|=(a<<j);
				G[k]|=(b<<i);
			}
			break ;
		}
	}
	//debug("shit")
	//for (int i=0; i<sz; i++) debug(G[i])
	dp[0][0][0]=1;
	for (int i=1; i<=sz; i++){
		int x=G[i-1]&((1<<(m-sz))-1);
		dp[i][0][0]=1;
		for (int j=1; j<=i; j++) for (int mask=0; mask<(1<<(m-sz)); mask++){
			dp[i][j][mask]=(dp[i-1][j][mask] + dp[i-1][j-1][mask^x])%mod;
		}
	}
	for (int j=0; j<=sz; j++)
		for (int mask=0; mask<(1<<(m-sz)); mask++)
			ans[j+__builtin_popcount(mask)]+=dp[sz][j][mask];
	
	for (int i=0; i<=m; i++){
		ans[i]%=mod;
		cout<<ans[i]*tav2%mod<<' ';
	}
	cout<<'\n';
	
	
	
	return 0;
}