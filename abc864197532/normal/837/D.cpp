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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500;

int dp[201][6000] = {};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,201) fop (j,0,6000) dp[i][j] = -1 << 30;
    dp[0][0] = 0;
    int n, k;
    lli tmp;
    cin >> n >> k;
    vector <pii> a(n, mp(0, 0));
    fop (i,0,n) {
        cin >> tmp;
        while (tmp % 2 == 0) {
            a[i].X++;
            tmp /= 2;
        }
        while (tmp % 5 == 0) {
            a[i].Y++;
            tmp /= 5;
        }
    }
    fop (i,0,n) {
        int x, y;
        tie(x, y) = a[i];
        FOP (j,k,0) {
            FOP (s,6000,0) if (s - y >= 0) {
                dp[j + 1][s] = max(dp[j + 1][s], dp[j][s - y] + x);
            }
        }
    }
    int ans = 0;
    fop (i,0,6000) ans = max(ans, min(dp[k][i], i));
    cout << ans << endl;
}