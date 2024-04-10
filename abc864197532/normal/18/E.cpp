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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

int odd[500][26], even[500][26], dp[500][26][26];
pii pre[500][26][26];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 26; ++k) if (s[j] != k + 'a') {
                if (j & 1) odd[i][k]++;
                else even[i][k]++;
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) dp[0][i][j] = 1 << 30;
            else dp[0][i][j] = even[0][i] + odd[0][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                dp[i][j][k] = 1 << 30;
                if (j == k) continue;
                for (int l = 0; l < 26; ++l) if (j != l) {
                    for (int ll = 0; ll < 26; ++ll) if (k != ll && l != ll) {
                        if (dp[i][j][k] > dp[i - 1][l][ll] + even[i][j] + odd[i][k]) {
                            pre[i][j][k] = mp(l, ll);
                            dp[i][j][k] = dp[i - 1][l][ll] + even[i][j] + odd[i][k];
                        }
                    }
                }
            }
        }
    }
    vector <string> ans(n);
    pii P = {0, 1};
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) if (i != j) {
            if (dp[n - 1][i][j] < dp[n - 1][P.X][P.Y]) {
                P = mp(i, j);
            }
        }
    }
    cout << dp[n - 1][P.X][P.Y] << endl;
    for (int i = n - 1; ~i; --i) {
        string now = string(m, 'a');
        for (int j = 0; j < m; ++j) {
            if (j & 1) now[j] = P.Y + 'a';
            else now[j] = P.X + 'a';
        }
        ans[i] = now;
        P = pre[i][P.X][P.Y];
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << endl;
}