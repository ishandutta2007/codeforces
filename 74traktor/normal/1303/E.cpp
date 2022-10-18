#include<bits/stdc++.h>

using namespace std;

int dp[405][405];
int inf = 1e9;

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        if ((int)t.size() > (int)s.size()) {
            cout << "NO" << '\n';
            continue;
        }
        s = "#" + s, t = "#" + t;
        for (int i = 0; i <= 402; ++i) {
            for (int j = 0; j <= 402; ++j) dp[i][j] = -inf;
        }
        dp[0][0] = 0;
        int ok = 0;
        for (int i = 1; i < (int)t.size(); ++i) {
            for (int j = 1; j < (int)s.size(); ++j) {
                for (int z = 0; z <= i; ++z) {
                    dp[j][z] = dp[j - 1][z];
                    if (z != 0 && s[j] == t[z]) {
                        dp[j][z] = max(dp[j][z], dp[j - 1][z - 1]);
                    }
                    int nxt = i + dp[j - 1][z] + 1;
                    if (nxt > 0 && nxt < (int)t.size() && s[j] == t[nxt]) {
                        dp[j][z] = max(dp[j][z], dp[j - 1][z] + 1);
                    }
                }
            }
            if (dp[(int)s.size() - 1][i] >= (int)t.size() - i - 1) ok = 1;
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}