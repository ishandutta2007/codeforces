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
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <lli> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> c[i];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        lli cur = 0, ans = cur, mx = 0;
        for (int i = 1; i < n; ++i) {
            lli lr = c[i] - 1 + abs(a[i] - b[i]) + 2;
            if (a[i] != b[i]) {
                lr = max(lr, c[i] - 1 + mx - abs(a[i] - b[i]) + 2);
            }
            mx = lr;
            ans = max(ans, lr);
        }
        cout << ans << endl;
    }
}