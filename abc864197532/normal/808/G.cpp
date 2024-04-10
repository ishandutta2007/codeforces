#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

vector <int> build_fail(string &s) {
    vector <int> f(s.length() + 1, 0);
    int k = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (k && s[k] != s[i]) k = f[k];
        if (s[k] == s[i]) k++;
        f[i + 1] = k;
    }
    return f;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    if (n < m) return cout << 0 << endl, 0;
    vector <int> f = build_fail(t);
    vector <vector <int>> nxt(m, vector <int> (26, 0));
    for (int i = 0; i < m; ++i) {
        for (int c = 0; c < 26; ++c) {
            if (i && (c + 'a') != t[i]) nxt[i][c] = nxt[f[i]][c];
            else nxt[i][c] = i;
        }
    }
    vector <vector <int>> dp(n + 1, vector <int>(m, -1 << 30));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] < 0) continue;
            for (char c = 'a'; c <= 'z'; ++c) if (s[i] == '?' || s[i] == c) {
                int k = nxt[j][c - 'a'];
                if (c == t[k]) k++;
                int re = 0;
                if (k == m) k = f[k], re = 1;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + re);
            }
        }
    }
    cout << *max_element(all(dp[n])) << endl;
}