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
const int mod = 1e9 + 7, abc = 864197532, N = 800007, logN = 17;
const double eps = 1e-9;

vector <double> v;

struct BIT {
    double bit[N];
    BIT ()  {
        for (int i = 0; i < N; ++i) bit[i] = 0;
    }
    void add (int p, double a) {
        for (int i = p; i < N; i += (i & -i)) bit[i] += a;
    }
    double query (int p) {
        double all = 0;
        for (int i = p; i > 0; i -= (i & -i)) all += bit[i];
        return all;
    }
} bit;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sy, a, b;
    cin >> sy >> a >> b;
    int n, q;
    cin >> n;
    vector <pii> seg(n);
    for (int i = 0; i < n; ++i) cin >> seg[i].X >> seg[i].Y, v.pb(seg[i].X), v.pb(seg[i].Y);
    cin >> q;
    vector <pii> query(q);
    vector <pair <double, double>> Q(q);
    for (int i = 0; i < q; ++i) {
        cin >> query[i].X >> query[i].Y;
        double x1 = 1.0 * query[i].X - 1.0 * (query[i].X - a) * query[i].Y / (query[i].Y - sy);
        double x2 = 1.0 * query[i].X - 1.0 * (query[i].X - b) * query[i].Y / (query[i].Y - sy);
        Q[i] = mp(x1, x2);
        v.pb(x1);
        v.pb(x2);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    bool is = false;
    auto same = [&](double a, double b) {
        return abs(a - b) <= eps;
    };
    for (int i = 0, j = -1; i < v.size(); ++i) {
        if (j + 1 < n && same(seg[j + 1].X, v[i])) j++, is = true;
        if (same(seg[j].Y, v[i])) is = false;
        if (is) bit.add(i + 2, v[i + 1] - v[i]);
    }
    for (int i = 0; i < q; ++i) {
        double x1, x2;
        tie(x1, x2) = Q[i];
        int f = lower_bound(all(v), x1) - v.begin(), t = lower_bound(all(v), x2) - v.begin();
        cout << fixed << setprecision(10) << (bit.query(t + 1) - bit.query(f + 1)) / query[i].Y * (query[i].Y - sy) << '\n';
    }
}