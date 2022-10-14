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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;
const long double eps = 1e-15;

bool les(ld a, ld b) {
    return b - a > eps;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, w, tt = 90;
        cin >> n >> w;
        vector <int> a(n + 2);
        a[0] = 0;
        a[n + 1] = w;
        fop (i,0,n) cin >> a[i + 1];
        auto ask = [&](ld t) {
            ld ans = 0;
            int sp = 1, cur = 0;
            bool is = true;
            ld t1 = t;
            fop (i,1,n + 2) {
                ld nxt = (long double)(a[i] - cur) / sp;
                if (les(t1, nxt)) {ans += cur + t1 * sp; is = 0; break;}
                else t1 -= nxt, cur = a[i];
                sp++;
            }
            if (is) return true;
            sp = 1;
            t1 = t;
            cur = w;
            is = true;
            FOP (i,n + 1,0) {
                ld nxt = (long double)(cur - a[i]) / sp;
                if (les(t1, nxt)) {ans += w - cur + t1 * sp; is = 0; break;}
                else t1 -= nxt, cur = a[i];
                sp++;
            }
            if (is) return true;
            return ans >= w;
        };
        ld l = 0, r = 1e9;
        while (tt--) {
            (ask((l + r) / 2) ? r : l) = (l + r) / 2;
        }
        cout << fixed << setprecision(10) << l << endl;
    }
}