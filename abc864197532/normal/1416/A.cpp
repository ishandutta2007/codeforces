#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
const int mod = 1e9 + 7, x = 864197532, N = 5000, logN = 17, K = 90002;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> cur(n + 1, 0), mx(n + 1, 0);
        fop (i,0,n) {
            cin >> a[i];
            mx[a[i]] = max(mx[a[i]], i - cur[a[i]]);
            cur[a[i]] = i + 1;
        }
        fop (i,1,n + 1) mx[i] = max(mx[i], n - cur[i]);
        vector <int> ans(n + 2, n + 1);
        fop (i,1,n + 1) ans[mx[i] + 1] = min(ans[mx[i] + 1], i);
        fop (i,1,n + 1) ans[i] = min(ans[i], ans[i - 1]);
        fop (i,1,n + 1) {
            if (ans[i] == n + 1) cout << -1 << ' ';
            else cout << ans[i] << ' ';
        }
        cout << endl;
    }
}