#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 500001, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m, 0)), d(n, vector <int> (n, 1 << 30)), d2(n, vector <int> (n, 1 << 30));
    fop (i,0,n) fop (j,0,m) cin >> a[i][j];
    fop (i,0,n) fop (j,0,n) {
        fop (k,0,m) {
            d[i][j] = min(d[i][j], abs(a[i][k] - a[j][k]));
        }
        fop (k,0,m - 1) {
            d2[i][j] = min(d2[i][j], abs(a[i][k] - a[j][k + 1]));
        }
    }
    if (n == 1) {
        int ans = 1 << 30;
        fop (i,0,m - 1) ans = min(ans, abs(a[0][i] - a[0][i + 1]));
        cout << ans << endl;
        return 0;
    }
    int dp[n][n][1 << n];
    fop (i,0,n) fop (j,0,n) fop (s,0,1 << n) dp[i][j][s] = 0;
    fop (i,0,n) fop (j,0,n) if (i ^ j) dp[i][j][(1 << i) | (1 << j)] = d[i][j];
    fop (s,0,1 << n) if (__builtin_popcount(s) >= 3) {
        fop (i,0,n) if (s & (1 << i)) {
            fop (j,0,n) if (s & (1 << j) && i ^ j) {
                fop (k,0,n) if (s & (1 << k) && k ^ j) {
                    dp[i][j][s] = max(dp[i][j][s], min(dp[i][k][s ^ (1 << j)], d[k][j]));
                }
            }
        }
    }
    int ans = 0;
    fop (i,0,n) fop (j,0,n) if (i ^ j) {
        ans = max(ans, min(dp[i][j][(1 << n) - 1], d2[j][i]));
    }
    cout << ans << endl;
}