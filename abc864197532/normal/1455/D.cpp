#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;


void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n), v;
    fop (i,0,n) cin >> a[i];
    bool is = true;
    fop (i,1,n) {
        is &= a[i - 1] <= a[i];
    }
    if (is) {
        cout << 0 << endl;
        return;
    }
    v = a;
    v.pb(x);
    sort(all(v));
    int ans = n + 1;
    fop (i,0,n + 1) if (v[i] > x) {
        vector <int> b;
        fop (j,0,n + 1) if (i ^ j) b.pb(v[j]);
        int cnt = 0;
        fop (i,0,n) {
            if (a[i] < b[i]) {
                cnt = -1;
                break;
            } else if (a[i] > b[i]) {
                cnt++;
            }
        }
        if (~cnt) ans = min(ans, cnt);
    }
    if (ans == n + 1) cout << -1 << endl;
    else cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}