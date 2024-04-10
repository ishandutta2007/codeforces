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
const int mod = 1e9 + 7, abc = 864197532, N = 3000005, logN = 20, K = 333;

void solve() {
    int n;
    cin >> n;
    vector <lli> b(n, 0), pre(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> b[i], pre[i + 1] = pre[i] + b[i];
    vector <lli> dp(n + 1, 0);
    dp[0] = 1;
    map <lli, lli> m1;
    m1[pre[0]] = 1;
    lli al = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (al + mod - m1[pre[i - 1]]) % mod;
        m1[pre[i - 1]] = (m1[pre[i - 1]] + dp[i]) % mod;
        al = (al + dp[i]) % mod;
    }
    lli ans = 0;
    for (lli &i : dp) ans = (ans + i) % mod;
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