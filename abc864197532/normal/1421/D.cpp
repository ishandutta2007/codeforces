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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli x, y;
        lli c[6];
        cin >> x >> y;
        fop (i,0,6) cin >> c[i];
        fop (_,0,10) {
            fop (i,0,6) {
                c[i] = min(c[i], c[(i + 1) % 6] + c[(i + 5) % 6]);
            }
        }
        lli ans = 0;
        if (x == 0) {
            if (y > 0) ans = y * c[1];
            else ans = -y * c[4];
        } else if (y == 0) {
            if (x > 0) ans = x * c[5];
            else ans = -x * c[2];
        } else if (x > 0) {
            if (y > 0) {
                if (c[0] <= c[1] + c[5]) {
                    ans = min(x, y) * c[0];
                    if (x > y) ans += c[5] * (x - y);
                    else ans += c[1] * (y - x);
                } else {
                    ans = x * c[5] + y * c[1];
                }
            } else {
                ans = x * c[5] - y * c[4];
            }
        } else if (x < 0) {
            if (y > 0) {
                ans = -x * c[2] + y * c[1];
            } else {
                x = -x, y = -y;
                if (c[3] <= c[2] + c[4]) {
                    ans = min(x, y) * c[3];
                    if (x > y) ans += c[2] * (x - y);
                    else ans += c[4] * (y - x);
                } else {
                    ans = x * c[2] + y * c[4];
                }
            }
        }
        cout << ans << endl;
    }
}