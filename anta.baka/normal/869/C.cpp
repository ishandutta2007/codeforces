#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int f[5001][5001];

int main() {
    for(int i = 1; i <= 5000; i++)
        for(int j = 1; j <= 5000; j++) {
            f[i][j] = (f[i - 1][j] + 1LL * j * (f[i - 1][j - 1] + 1)) % mod;
        }
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((1LL * (f[a][b] + 1) * (f[b][c] + 1)) % mod * (f[c][a] + 1)) % mod;
}