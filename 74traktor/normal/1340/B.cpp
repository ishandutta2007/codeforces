#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int dp[maxn][maxn];
int a[maxn][10];
vector < string > Q = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 0; j <= 9; ++j) {
            int ok = 1, cnt = 0;
            for (int pos = 0; pos < 7; ++pos) {
                if (s[pos] == '1' && Q[j][pos] == '0') ok = 0;
                if (s[pos] == '0' && Q[j][pos] == '1') cnt++;
            }
            if (!ok) a[i][j] = 2005;
            else a[i][j] = cnt;
        }
    }
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= 9; ++j) {
            for (int sum = 0; sum <= k; ++sum) {
                if (sum - a[i][j] >= 0) dp[i][sum] = (dp[i][sum]|dp[i + 1][sum - a[i][j]]);
            }
        }
    }
    //cout << a[1][9] << endl;
    if (dp[1][k] == 0) cout << -1;
    else {
        int i = 1, j = k;
        string answer = "";
        while (i <= n) {
            for (int t = 9; t >= 0; --t) {
                if (j >= a[i][t] && dp[i][j] == dp[i + 1][j - a[i][t]]) {
                    answer += char('0' + t);
                    j -= a[i][t], ++i;
                    break;
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}