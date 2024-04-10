#include <iostream>
#include <string>

using namespace std;

const int MAXN = 5005, MOD = 1000 * 1000 * 1000 + 7;
int z[MAXN][MAXN], dp[MAXN][MAXN];
string s;

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

bool cmp(int i, int j, int k) {
    if(z[i][j] >= k - j + 1)
        return false;
    return s[i + z[i][j]] < s[j + z[i][j]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        for(int j = i + 1, l = i, r = i; j < n; j++) {
            if(j <= r)
                z[i][j] = min(r - j + 1, z[i][i + j - l]);
            while(j + z[i][j] < n && s[i + z[i][j]] == s[j + z[i][j]])
                z[i][j]++;
            if(j + z[i][j] - 1 > r) {
                l = j;
                r = j + z[i][j] - 1;
            }
        }
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == '0')
            continue;
        for(int j = i - 2; j >= 0; j--)
            add(dp[j][i - 1], dp[j + 1][i - 1]);
        for(int j = i; j < n; j++) {
            int k = i - (j - i) - 1;
            if(k < 0 || !cmp(k, i, j))
                k = max(0, k + 1);
            add(dp[i][j], dp[k][i - 1]);
        }
    }
    for(int i = n - 2; i >= 0; i--)
        add(dp[i][n - 1], dp[i + 1][n - 1]);
    cout << dp[0][n - 1] << '\n';
    return 0;
}