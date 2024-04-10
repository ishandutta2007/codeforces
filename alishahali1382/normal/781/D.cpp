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
const int mod = 1000000007;
const int MAXN = 502, LOG=60;

int n, m, k, u, v, x, y, t, a, b;
bitset<MAXN> dp[2][LOG][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		dp[x][0][u].set(v);
	}
	
	for (int i=1; i<LOG; i++) for (int typ=0; typ<2; typ++) for (int u=1; u<=n; u++) for (int v=dp[typ][i-1][u]._Find_first(); v<=n; v=dp[typ][i-1][u]._Find_next(v)) dp[typ][i][u]|=dp[!typ][i-1][v];
	
	ll ans=0;
	bitset<MAXN> now, go;
	int typ=0;
	now.set(1);
	for (int i=LOG-1; i>=0; i--){
		go.reset();
		for (int v=now._Find_first(); v<=n; v=now._Find_next(v)) go|=dp[typ][i][v];
		if (go.count()){
			typ=!typ;
			now=go;
			ans|=(1ll<<i);
		}
	}
	
	if (ans>1e18) ans=-1;
	cout<<ans<<'\n';
	
	return 0;
}
/*
3 6
3 1 1
1 2 1
2 1 1
1 3 0
3 2 1
2 2 0

*/