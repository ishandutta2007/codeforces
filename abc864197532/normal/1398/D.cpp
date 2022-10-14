#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, g, b;
    cin >> r >> g >> b;
    vector <lli> v1(r), v2(g), v3(b);
    fop (i,0,r) cin >> v1[i];
    fop (i,0,g) cin >> v2[i];
    fop (i,0,b) cin >> v3[i];
    sort(all(v1));
    sort(all(v2));
    sort(all(v3));
    lli dp[r + 1][g + 1][b + 1];
    fop (i,0,r + 1) fop (j,0,g + 1) fop (k,0,b + 1) dp[i][j][k] = 0;
    fop (i,0,r + 1) fop (j,0,g + 1) fop (k,0,b + 1) {
    	if (i && j) {
    		dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + v1[i - 1] * v2[j - 1]);
		}
		if (j && k) {
    		dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + v2[j - 1] * v3[k - 1]);
		}
		if (i && k) {
    		dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + v1[i - 1] * v3[k - 1]);
		}
	}
	cout << dp[r][g][b] << endl;
}