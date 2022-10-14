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
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 1 << 20;

void solve() {
    int n;
    lli w;
    cin >> n >> w;
    vector <int> a(n), p(n);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) {
        if ((w + 1) / 2 <= a[i] && a[i] <= w) {
            cout << 1 << endl << i + 1 << endl;
            return;
        }
    }
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] < a[j];
    });
    while (p.size() && a[p.back()] > w) p.pop_back();
    vector <int> ans;
    lli cur = 0;
    fop (i,0,n) {
        cur += a[p[i]];
        ans.pb(p[i] + 1);
        if ((w + 1) / 2 <= cur && cur <= w) {
            cout << ans.size() << endl;
            printv(ans);
            return;
        }
    }
    cout << -1 << endl;
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