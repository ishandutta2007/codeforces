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

double dp[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, len;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> len;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; ~j; --j) {
            for (int k = len; ~k; --k) {
                if (k + a[i] <= len) {
                    dp[j + 1][k + a[i]] += dp[j][k] / (n - j);
                 }
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= len; ++j) {
            for (int k = 1; k <= i; ++k) dp[i][j] *= k;
            ans += dp[i][j];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}