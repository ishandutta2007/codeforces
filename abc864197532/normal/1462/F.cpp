#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

struct BIT {
    vector <long long> bit;
    int n;

    BIT(int _n) : n(_n) {
        bit.assign(n, 0);
    }

    void add(int p, long long a) {
        for (int i = p; i < n; i += (i & -i)) bit[i] += a;
    }

    long long query(int p) {
        long long all = 0;
        for (int i = p; i > 0; i -= (i & -i)) all += bit[i];
        return all;
    }
};

void solve() {
    int n;
    cin >> n;
    vector <pii> seg(n);
    vector <int> v;
    for (int i = 0; i < n; ++i) cin >> seg[i].X >> seg[i].Y, v.pb(seg[i].X), v.pb(seg[i].Y);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    BIT bit1(v.size() + 2), bit2(v.size() + 2);
    /*
     * _r < l || _l > r
     */
    lli ans = n;
    for (int i = 0; i < n; ++i) {
        seg[i].X = lower_bound(all(v), seg[i].X) - v.begin();
        seg[i].Y = lower_bound(all(v), seg[i].Y) - v.begin();
        bit1.add(seg[i].X + 2, 1);
        bit2.add(seg[i].Y + 2, 1);
    }
    for (int i = 0; i < n; ++i) {
        ans = min(ans, bit2.query(seg[i].X + 1) + n - bit1.query(seg[i].Y + 2));
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