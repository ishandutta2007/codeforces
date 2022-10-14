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
const int mod = 1e9 + 7, abc = 864197532, N = 300000, logN = 18, M = 2e7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli A, B, n;
        cin >> A >> B >> n;
        vector <pii> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].X;
        for (int i = 0; i < n; ++i) cin >> a[i].Y;
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            lli round = (a[i].Y + A - 1) / A;
            B -= round * a[i].X;
        }
        if (B + a[n - 1].X <= 0) cout << "NO\n";
        else cout << "YES\n";
    }
}