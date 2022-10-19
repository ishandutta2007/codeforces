#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 2001;

int dp[N][N];
int pref[N][26];
int pref2[N][26];

bool check(string s, string t) {
    sort(all(s));
    sort(all(t));
    return s == t;
}

void solve() {
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t;
    if (!check(s, t)) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < 26; i++) {
        pref[0][i] = 0;
        pref2[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i][j] = pref[i - 1][j];
            pref2[i][j] = pref2[i - 1][j];
        }
        pref[i][s[i - 1] - 'a']++;
        pref2[i][t[i - 1] - 'a']++;        
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = 1e9;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            if (pref[i][s[i - 1] - 'a'] <= pref2[j][s[i - 1] - 'a']) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (pref[i][t[j - 1] - 'a'] <= pref2[j - 1][t[j - 1] - 'a']) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    } 

    cout << dp[n][n] << '\n';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}