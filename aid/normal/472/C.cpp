#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char dp[MAXN][2];
int p[MAXN];
string s[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i][0] >> s[i][1];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    dp[0][0] = true;
    dp[0][1] = true;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                if(dp[i - 1][k] && s[p[i]][j] > s[p[i - 1]][k]) {
                    dp[i][j] = true;
                    break;
                }
    if(dp[n - 1][0] || dp[n - 1][1])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}