#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;


inline bool isAlphanumeric(char c) {
    return ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z') ||
           ('0' <= c && c <= '9');
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T-- > 0) {
        int n;
        cin >> n;

        vector<string> names(n);
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
        }

        int m;
        cin >> m;
        cin.get();

        vector<string> message(m);
        vector<int> user(m);
        vector<vector<bool>> diff(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            string s;
            getline(cin, s);
            int pos = s.find_first_of(":");
            message[i] = string(s.begin() + pos + 1, s.end());
            string cuser = string(s.begin(), s.begin() + pos);
            if (cuser == "?") {
                user[i] = -1;
            } else {
                user[i] = find(names.begin(), names.end(), cuser) - names.begin();
            }
            for (int j = 0; j < n; ++j) {
                bool isFound = false;
                int pos = 0;
                while (!isFound) {
                    pos = message[i].find(names[j], pos);
                    if (pos == string::npos) {
                        break;
                    }
                    if ((pos == 0 || !isAlphanumeric(message[i][pos - 1])) &&
                        (pos + SZ(names[j]) == SZ(message[i]) ||
                         !isAlphanumeric(message[i][pos + SZ(names[j])]))) {
                        isFound = true;
                    } else {
                        pos += SZ(names[j]);
                    }
                }
                diff[i][j] = isFound;
            }
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (user[i - 1] == -1) {
                for (int j = 1; j <= n; ++j) {
                    if (diff[i - 1][j - 1]) {
                        continue;
                    }
                    for (int k = 0; k <= n; ++k) {
                        dp[i][j] = dp[i][j] || (k != j && dp[i - 1][k]);
                    }
                }
            } else {
                int j = user[i - 1] + 1;
                if (!diff[i - 1][j - 1]) {
                    for (int k = 0; k <= n; ++k) {
                        dp[i][j] = dp[i][j] || (k != j && dp[i - 1][k]);
                    }
                }
            }
        }

        int u = 1;
        while (u <= n && !dp[m][u]) {
            ++u;
        }
        if (u == n + 1) {
            cout << "Impossible\n";
        } else {
            vector<string> lines;
            for (int i = m; i > 0; --i) {
                lines.push_back(names[u - 1] + ":" + message[i - 1]);
                for (int j = 0; j <= n; ++j) {
                    if (j != u && dp[i - 1][j]) {
                        u = j;
                        break;
                    }
                }
            }
            reverse(lines.begin(), lines.end());
            for (const string& p: lines) {
                cout << p << '\n';
            }
        }
    }
}