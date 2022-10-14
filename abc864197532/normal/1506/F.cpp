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
const int mod = 1e9 + 7, abc = 864197532, N = 1000, logN = 20, K = 333;

int ask(int r, int c, int f) {
    if (r == c) {
        if (f) return 0;
        return r;
    }
    if (c == 0) {
        return (r + f) / 2;
    }
    if (f) {
        return ask(r - c, 0, f);
    } else {
        return ask(r - 1, c, f ^ 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].X;
    for (int i = 0; i < n; ++i) cin >> a[i].Y;
    sort(all(a));
    if (a[0] != mp(1, 1)) a.insert(a.begin(), mp(1, 1)), n++;
    lli ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int dr = a[i + 1].X - a[i].X, dc = a[i + 1].Y - a[i].Y;
        ans += ask(dr, dc, (a[i].X + a[i].Y) & 1);
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