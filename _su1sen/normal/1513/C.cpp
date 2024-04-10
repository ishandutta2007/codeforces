#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

constexpr long long mod = 1000000007;

constexpr long long add(long long x, long long y) {
    long long z = x + y;
    return z >= mod ? z - mod : z;
}

constexpr int M = 200001;

int main() {
    vector<vector<vector<long long>>> X(M, vector<vector<long long>>(10, vector<long long>(10, 0)));
    for (int i = 0; i < 10; ++i) {
        X[0][i][i] = 1;
    }
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < 10; ++j) {
            X[i][j][0] = add(X[i][j][0], X[i - 1][j][1]);
            X[i][j][1] = add(X[i][j][1], X[i - 1][j][2]);
            X[i][j][2] = add(X[i][j][2], X[i - 1][j][3]);
            X[i][j][3] = add(X[i][j][3], X[i - 1][j][4]);
            X[i][j][4] = add(X[i][j][4], X[i - 1][j][5]);
            X[i][j][5] = add(X[i][j][5], X[i - 1][j][6]);
            X[i][j][6] = add(X[i][j][6], X[i - 1][j][7]);
            X[i][j][7] = add(X[i][j][7], X[i - 1][j][8]);
            X[i][j][8] = add(X[i][j][8], X[i - 1][j][9]);
            X[i][j][9] = add(X[i][j][9], add(X[i - 1][j][0], X[i - 1][j][1]));
        }
    }

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t --> 0) {
        int n, m;
        cin >> n >> m;
        vector<long long> c(10, 0);
        while (n) {
            ++c[n % 10];
            n /= 10;
        }
        long long s = 0;
        for (int i = 0; i < 10; ++i) {
            s += X[m][i][0] * c[0] % mod;
            s += X[m][i][1] * c[1] % mod;
            s += X[m][i][2] * c[2] % mod;
            s += X[m][i][3] * c[3] % mod;
            s += X[m][i][4] * c[4] % mod;
            s += X[m][i][5] * c[5] % mod;
            s += X[m][i][6] * c[6] % mod;
            s += X[m][i][7] * c[7] % mod;
            s += X[m][i][8] * c[8] % mod;
            s += X[m][i][9] * c[9] % mod;
        }
        cout << s % mod << '\n';
    }
    return 0;
}