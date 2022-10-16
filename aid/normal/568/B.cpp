#include <iostream>

using namespace std;

const int MAXN = 4005, MOD = 1000 * 1000 * 1000 + 7;
int c[MAXN][MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if(c[i][j] >= MOD)
                c[i][j] -= MOD;
        }
    }
    b[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            b[i + 1] = (b[i + 1] + (long long)c[i][j] * b[j]) % MOD;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + (long long)c[n][i] * b[i]) % MOD;
    cout << ans << '\n';
    return 0;
}