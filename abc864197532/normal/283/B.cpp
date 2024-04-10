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
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 200087, logN = 17;

int n;
vector <vector <lli>> dp;
vector <vector <bool>> vis;
vector <int> input;

lli solve(int a, int b) {
    if (a == 0) return -1;
    if (a < 0 || a >= n) return 0;
    if (dp[a][b] != -2) return dp[a][b];
    if (vis[a][b]) {
        vis[a][b] = false;
        return dp[a][b] = -1;
    }
    vis[a][b] = true;
    lli k;
    if (b) k = solve(a - input[a], b ^ 1);
    else k = solve(a + input[a], b ^ 1);
    if (k == -1) {
        dp[a][b] = -1;
    } else {
        dp[a][b] = k + input[a];
    }
    vis[a][b] = false;
    return dp[a][b];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	input.resize(n);
	dp.resize(n, vector<lli>(2, -2));
	vis.resize(n, vector<bool>(2, false));
	fop (i,1,n) cin >> input[i];
	fop (i,1,n) cout << (solve(i, 1) == -1 ? -1 : dp[i][1] + i) << endl;
}