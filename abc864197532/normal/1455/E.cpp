#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

int x[4], y[4], p[4];

lli f(int k) {
    lli ans = 5e9;
    do {
        int a[4] = {x[p[0]], x[p[1]] - k, x[p[2]], x[p[3]] - k};
        int b[4] = {y[p[0]], y[p[1]], y[p[2]] - k, y[p[3]] - k};
        sort(a, a + 4);
        sort(b, b + 4);
        lli ans1 = a[3] + a[2];
        ans = min(ans, ans1 - a[1] - a[0] + b[3] + b[2] - b[1] - b[0]);
    } while (next_permutation(p, p + 4));
    return ans;
};

void solve() {
    for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];
    iota(p, p + 4, 0);
    lli ans = 5e9;
    int l = -1, r = 1 << 30;
    while (r - l > 1) {
        lli mid = l + r >> 1;
        if (f(mid + 1) > f(mid)) r = mid;
        else l = mid;
    }
    cout << f(r) << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    /*
    vector <int> x = {1, 2, 2, 4}, y = {6, 2, 5, 1};
    fop (i,0,4) x[i] = uniform_int_distribution<int>(0, 1000)(rng);
    fop (i,0,4) y[i] = uniform_int_distribution<int>(0, 1000)(rng);
    fop (k,0,1001) {
        cout << k << ' ';
        vector <int> p(4);
        iota(all(p), 0);
        int ans = 1 << 30;
        do {
            vector <int> a = {x[p[0]], x[p[1]] - k, x[p[2]], x[p[3]] - k};
            vector <int> b = {y[p[0]], y[p[1]], y[p[2]] - k, y[p[3]] - k};
            sort(all(a)), sort(all(b));
            ans = min(ans, a[3] + a[2] - a[1] - a[0] + b[3] + b[2] - b[1] - b[0]);
        } while (next_permutation(all(p)));
        cout << ans << endl;
    }
     */
}