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
const int mod = 1e9 + 7, abc = 864197532, N = 51, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    int mn = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], mn = max(mn, min(a[i].X, a[i].Y));
    int ans = 1 << 30;
    for (int C = mn; C <= 1000; ++C) {
        vector <int> del;
        int w = 0, need = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].X > C) {
                w += a[i].X;
            } else if (a[i].Y > C) {
                need++;
                w += a[i].Y;
            } else {
                if (a[i].X > a[i].Y) {
                    del.pb(a[i].Y - a[i].X);
                }
                w += a[i].X;
            }
        }
        if (need > n / 2) continue;
        sort(all(del));
        for (int i = 0; need + i + 1 <= n / 2 && i < del.size(); ++i) {
            w += del[i];
        }
        ans = min(ans, w * C);
    }
    cout << ans << endl;
}