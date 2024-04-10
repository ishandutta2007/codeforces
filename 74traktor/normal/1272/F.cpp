#include<bits/stdc++.h>

using namespace std;

int dp[205][205][505];
int inf = 1e9;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    s1 = "0" + s1, s2 = "0" + s2;
    int n1 = (int)s1.size(), n2 = (int)s2.size();
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            for (int bal = 0; bal <= 500; ++bal) dp[i][j][bal] = inf;
        }
    }
    dp[1][1][0] = 0;
    s1 += "#", s2 += "#";
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            for (int bal = 0; bal <= 500; ++bal) {
                if (bal > 0) {
                    if (s1[i - 1] == '(') dp[i][j][bal] = min(dp[i][j][bal], dp[i - 1][j][bal - 1] + 1);
                    if (s2[j - 1] == '(') dp[i][j][bal] = min(dp[i][j][bal], dp[i][j - 1][bal - 1] + 1);
                    if (s1[i - 1] == '(' && s2[j - 1] == '(') dp[i][j][bal] = min(dp[i][j][bal], dp[i - 1][j - 1][bal - 1] + 1);
                }
                if (s1[i - 1] == ')') dp[i][j][bal] = min(dp[i][j][bal], dp[i - 1][j][bal + 1] + 1);
                if (s2[j - 1] == ')') dp[i][j][bal] = min(dp[i][j][bal], dp[i][j - 1][bal + 1] + 1);
                if (s1[i - 1] == ')' && s2[j - 1] == ')') dp[i][j][bal] = min(dp[i][j][bal], dp[i - 1][j - 1][bal + 1] + 1);
            }
            int mx = -inf;
            for (int bal = 0; bal <= 500; ++bal) {
                mx = max(mx, bal - dp[i][j][bal]);
                dp[i][j][bal] = min(dp[i][j][bal], bal - mx);
            }
            mx = inf;
            for (int bal = 500; bal >= 0; --bal) {
                mx = min(mx, dp[i][j][bal] + bal);
                dp[i][j][bal] = min(dp[i][j][bal], mx - bal);
            }
        }
    }
    //cout << dp[n1][n2][0] << '\n';
    int i = n1, j = n2, z = 0;
    string answer;
    while (1) {
        //cout << i << " " << j << " " << z << " " << answer << endl;
        if (i == 1 && j == 1 && z == 0) break;
        int mx = -inf, ok = 0, where = -1;
        for (int bal = 0; bal < z; ++bal) {
            if (bal - dp[i][j][bal] > mx) where = bal;
            mx = max(mx, bal - dp[i][j][bal]);
        }
        if (dp[i][j][z] == z - mx) {
            for (int cnt = 0; cnt < z - where; ++cnt) answer += "(";
            z = where;
            continue;
        }
        mx = inf;
        for (int bal = 500; bal > z; --bal) {
            if (dp[i][j][bal] + bal < mx) where = bal;
            mx = min(mx, dp[i][j][bal] + bal);
        }
        if (dp[i][j][z] == mx - z) {
            for (int cnt = 0; cnt < where - z; ++cnt) answer += ")";
            z = where;
            continue;
        }
        if (z > 0) {
            if (s1[i - 1] == '(' && dp[i][j][z] == dp[i - 1][j][z - 1] + 1) {
                answer += "(";
                i--, z--;
                continue;
            }
            if (s2[j - 1] == '(' && dp[i][j][z] == dp[i][j - 1][z - 1] + 1) {
                answer += "(";
                j--, z--;
                continue;
            }
            if (s1[i - 1] == '(' && s2[j - 1] == '(' && dp[i][j][z] == dp[i - 1][j - 1][z - 1] + 1) {
                i--, j--, z--;
                answer += "(";
                continue;
            }
        }
        if (s1[i - 1] == ')' && dp[i][j][z] == dp[i - 1][j][z + 1] + 1) {
            answer += ")";
            i--, z++;
            continue;
        }
        if (s2[j - 1] == ')' && dp[i][j][z] == dp[i][j - 1][z + 1] + 1) {
            answer += ")";
            j--, z++;
            continue;
        }
        if (s1[i - 1] == ')' && s2[j - 1] == ')' && dp[i][j][z] == dp[i - 1][j - 1][z + 1] + 1) {
            i--, j--, z++;
            answer += ")";
            continue;
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
    return 0;
}