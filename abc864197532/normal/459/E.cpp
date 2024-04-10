#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

vector <pii> edge[N];
vector <int> dp(3 * N, 0), pre(3 * N, -1);

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v, w;
	cin >> n >> m;
	fop (i,0,m) {
		cin >> u >> v >> w; u--; v--;
		edge[w].pb({u, v});
	}
	vector <int> tmp(3 * N, 0);
	fop (i,0,N) {
		for (auto A : edge[i]) {
			tmp[A.Y] = max(tmp[A.Y], dp[A.X] + 1);
		}
		for (auto A : edge[i]) {
			dp[A.Y] = max(tmp[A.Y], dp[A.Y]);
			tmp[A.Y] = 0;
		}
	}
	cout << *max_element(all(dp)) << endl;
}