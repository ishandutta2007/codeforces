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
const int mod = 998244353, abc = 864197532, N = 402, logN = 17, K = 333, INF = 5e8;

int dp[2][N][N][3][3];
int sum[N];

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void del(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt[26];
    for (int i = 0; i < 26; ++i) cin >> cnt[i];
    dp[0][0][0][2][2] = 24 * 24;
    dp[0][0][1][2][1] = dp[0][0][1][1][2] = 24;
    dp[0][0][2][1][1] = 1;
    dp[0][1][0][2][0] = dp[0][1][0][0][2] = 24;
    dp[0][1][1][0][1] = dp[0][1][1][1][0] = 1;
    dp[0][2][0][0][0] = 1;
    for (int i = 2; i < n; ++i) {
        for (int a = 0; a <= i; ++a) for (int b = 0; a + b <= i; ++b) {
            for (int prel = 0; prel < 3; ++prel) for (int prer = 0; prer < 3; ++prer) {
                dp[i & 1 ^ 1][a][b][prel][prer] = 0;
            }
        }
        for (int a = 0; a <= i; ++a) for (int b = 0; a + b <= i; ++b) {
            for (int place = 0; place < 3; ++place) {
                for (int prel = 0; prel < 3; ++prel) for (int prer = 0; prer < 3; ++prer) {
                    if (place < 2 && prel == place) continue;
                    int na = a + (place == 0), nb = b + (place == 1), letter = (place < 2 ? 1 : 24 - (prel == place));
                    add(dp[i & 1 ^ 1][na][nb][prer][place], 1ll * dp[i & 1][a][b][prel][prer] * letter % mod);
                }
            }
        }
    }
    int ans = 0;
    for (int a = 0; a <= n; ++a) for (int b = 0; a + b <= n; ++b) {
        for (int prel = 0; prel < 3; ++prel) for (int prer = 0; prer < 3; ++prer) {
            add(sum[a], dp[n & 1][a][b][prel][prer]);
        }
    }
    for (int i = 0; i <= n; ++i) add(ans, sum[i]);
    lli tans = 26 * 26;
    for (int i = 2; i < n; ++i) tans = tans * 25 % mod;
    for (int i = 0; i < 26; ++i) for (int c = cnt[i] + 1; c <= n; ++c) {
        del(ans, sum[c]);
    }
    for (int i = 0; i < 26; ++i) for (int j = i + 1; j < 26; ++j) {
        for (int c1 = cnt[i] + 1; c1 <= n; ++c1) for (int c2 = cnt[j] + 1; c2 <= n; ++c2) {
            for (int prel = 0; prel < 3; ++prel) for (int prer = 0; prer < 3; ++prer) {
                add(ans, dp[n & 1][c1][c2][prel][prer]);
            }
        }
    }
    cout << ans << endl;
}