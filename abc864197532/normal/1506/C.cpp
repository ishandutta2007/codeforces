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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        int ans = n + m;
        for (int i = 0; i < n; ++i) for (int ii = 1; i + ii <= n; ++ii) {
            for (int j = 0; j < m; ++j) for (int jj = 1; j + jj <= m; ++jj) {
                if (s.substr(i, ii) == t.substr(j, jj)) {
                    ans = min(ans, n + m - ii - jj);
                }
            }
        }
        cout << ans << endl;
    }
}