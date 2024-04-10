#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long f[101][101][101], g[101][101][101];

int main(int argc, char *argv[]) {
    int n, X;
    cin >> n >> X;
    string s;
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        for (int k = 0; k < 2; k++) {
            string t = s.substr(0, i) + (char) (k + '0');
            for (int j = min((int)s.size(), i + 1); j >= 0; j--) {
                if (s.substr(0, j) == (t.substr(t.size() - j))) {
                    f[k][i][j] = 1;
                    if (j == s.size()) g[k][i][j] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= X; i++) {
        for (int j = 0; j <= s.length(); j++) {
            for (int k = 0; k <= s.length(); k++) {
                f[i][j][k] = (f[i - 1][j][k] + f[i - 2][j][k]) % mod;
                g[i][j][k] = (g[i - 1][j][k] + g[i - 2][j][k]) % mod;
                for (int h = 0; h <= s.length(); h++) {
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][h] * f[i - 2][h][k]) % mod;
                    g[i][j][k] = (g[i][j][k] + g[i - 1][j][h] * f[i - 2][h][k] + f[i - 1][j][h] * g[i - 2][h][k]) % mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= s.length(); i++) {
        ans = (ans + g[X][0][i]) % mod;
    }
    cout << ans << endl;
    return 0;

    
}