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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

double dp[2][N];
lli pw[19];

lli ask(lli x) {
    int n = to_string(x).length();
    lli ans = 0;
    for (int i = n - 1; ~i; --i) {
        ans += min(x, pw[i] * 2 - 1) - pw[i] + 1;
        x = pw[i] - 1;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i <= 18; ++i) pw[i] = pw[i - 1] * 10;
    int n, k;
    cin >> n;
    vector <lli> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i], l[i]--;
    dp[1][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) dp[i & 1][j] = 0;
        lli ok = ask(r[i]) - ask(l[i]);
        for (int j = i; ~j; --j) {
            dp[i & 1][j + 1] += dp[i & 1 ^ 1][j] * ((double)ok / (r[i] - l[i]));
            dp[i & 1][j] += dp[i & 1 ^ 1][j] * (1.0 - (double)ok / (r[i] - l[i]));
        }
    }
    double ans = 0;
    cin >> k;
    k = (k * n + 99) / 100;
    for (int i = k; i <= n; ++i) {
        ans += dp[n & 1 ^ 1][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
}