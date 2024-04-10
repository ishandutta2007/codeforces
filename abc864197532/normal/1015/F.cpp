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
const int mod = 1e9 + 7, abc = 864197532, N = 205, K = 111;

vector <int> build_fail(string s) {
    int n = s.length();
    vector <int> f(n + 1, 0);
    int k = 0;
    for (int i = 1; i < n; ++i) {
        while (k && s[k] != s[i]) k = f[k];
        if (s[k] == s[i]) k++;
        f[i + 1] = k;
    }
    return f;
}

int dp[2][N][N][2];

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int m = s.length();
    vector <int> f = build_fail(s);
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d <= n; ++d) for (int o : {0, 1}) {
                dp[i & 1 ^ 1][j][d][o] = 0;
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d <= n; ++d) for (int o : {0, 1}) {
                if (dp[i & 1][j][d][o] == 0) continue;
                {
                    int nj = j, nd = d + 1, no = o;
                    while (nj && '(' != s[nj]) nj = f[nj];
                    if ('(' == s[nj]) nj++;
                    if (nj == m) nj = f[nj], no |= 1;
                    add(dp[i & 1 ^ 1][nj][nd][no], dp[i & 1][j][d][o]);
                }
                {
                    int nj = j, nd = d - 1, no = o;
                    while (nj && ')' != s[nj]) nj = f[nj];
                    if (')' == s[nj]) nj++;
                    if (nj == m) nj = f[nj], no |= 1;
                    if (nd >= 0) add(dp[i & 1 ^ 1][nj][nd][no], dp[i & 1][j][d][o]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        add(ans, dp[0][i][0][1]);
    }
    cout << ans << endl;
}