#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <lli> a(n);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    if (n >= 100) {
        lli ans = 0;
        fop (i,0,n) ans += a[i] - 1;
        cout << ans << endl;
    } else {
        if (n == 1) {
            cout << 0 << endl;
        } else {
            lli ans = 1ll << 60, now = 1;
            while (now <= 1ll << 20) {
                lli tmp = 0, cur = 1;
                bool is = true;
                fop (i,0,n) {
                    if (abs(a[i] - cur) + tmp > ans) {
                        is = false;
                        break;
                    }
                    tmp += abs(a[i] - cur);
                    cur = cur * now;
                }
                now++;
                if (is) ans = min(ans, tmp);
            }
            cout << ans << endl;
        }
    }
}