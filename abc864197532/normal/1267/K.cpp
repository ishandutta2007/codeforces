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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli dp[30][30] = {};
    dp[1][1] = dp[1][0] = 1;
    for (int i = 2; i < 30; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        lli x;
        cin >> x;
        vector <int> cnt(30, 0);
        int now = 2, n = 0;
        while (x) {
            cnt[x % now]++;
            x /= now;
            now++;
            n++;
        }
        lli ans1 = 1, ans2 = 1;
        int empty = 0;
        int cur = n;
        while (~cur) {
            int x = cnt[cur];
            if (cur) empty++;
            if (x) {
                ans1 = ans1 * dp[empty][x];
                empty -= x;
            }
            cur--;
        }
        if (cnt[0] && cnt[n] == 0) {
            cnt[0]--;
            cur = n - 1;
            empty = 0;
            while (~cur) {
                int x = cnt[cur];
                if (cur) empty++;
                if (x) {
                    ans2 = ans2 * dp[empty][x];
                    empty -= x;
                }
                cur--;
            }
        } else {
            ans2 = 0;
        }
        cout << ans1 - ans2 - 1 << endl;
    }
}