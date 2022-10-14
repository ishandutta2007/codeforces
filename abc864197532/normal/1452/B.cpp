#include <bits/stdc++.h>
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
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 100;

void solve() {
    int n;
    cin >> n;
    vector <lli> a(n), v;
    lli pre = 0;
    fop (i,0,n) cin >> a[i], pre += a[i];
    v = a;
    sort(rall(v));
    lli ans = pre % (n - 1);
    ans = (n - 1 - ans) % (n - 1);
    fop (i,0,n) {
        lli tmp = (v[0] == a[i] ? v[1] : v[0]) * (n - 1) - (pre - a[i]) - a[i];
        if (tmp > 0) ans = max(ans, tmp);
    }
    cout << ans << endl;
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