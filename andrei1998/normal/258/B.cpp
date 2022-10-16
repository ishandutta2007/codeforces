#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int n;
int nr[15];

int dp[15][15][2]; //dp[i][j][0 / 1] = primele i cifre marcate, j cifre speciale, 0 = < , 1 = ==

int cate[15];
int invs[15];

int putere(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * putere(a, b - 1)) % mod;
    else {
        int aux = putere(a, b >> 1);
        return (1LL * aux * aux) % mod;
    }
}

int get_aranj(int n, int k) {
    int ans = 1;
    for (int i = 1; i <= k; ++ i) {
        ans = (ans * (n - i + 1LL)) % mod;
        ans = (1LL * ans * invs[i]) % mod;
    }
    return ans;
}

int dp2[15][15][255];

int main()
{
    for (int i = 1; i <= 10; ++ i)
        invs[i] = putere(i, mod - 2);

    int m = 0;
    cin >> m;

    while (m) {
        nr[++ n] = m % 10;
        m /= 10;
    }
    reverse(nr + 1, nr + n + 1);

    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= 12; ++ j) {
            //Cazul cand era <
            for (int cifra = 0; cifra <= 9; ++ cifra) {
                dp[i + 1][j + (cifra == 4 || cifra == 7)][0] += dp[i][j][0];
                if (dp[i + 1][j + (cifra == 4 || cifra == 7)][0] >= mod)
                    dp[i + 1][j + (cifra == 4 || cifra == 7)][0] -= mod;
            }

            //Cazul cand era ==
            for (int cifra = 0; cifra <= nr[i + 1]; ++ cifra) {
                dp[i + 1][j + (cifra == 4 || cifra == 7)][cifra == nr[i + 1]] += dp[i][j][1];
                if (dp[i + 1][j + (cifra == 4 || cifra == 7)][cifra == nr[i + 1]] >= mod)
                    dp[i + 1][j + (cifra == 4 || cifra == 7)][cifra == nr[i + 1]] -= mod;
            }
        }

    for (int i = 0; i <= 10; ++ i)
        cate[i] = (dp[n][i][0] + dp[n][i][1]) % mod;

    cate[0] --;
   // for (int i = 0; i <= 10; ++ i)
   //     cout << i << ' ' << cate[i] << endl;

    //Dinamica 2
    dp2[0][0][0] = 1;

    //dp2[i][j][k] = urna i, j luate, suma k
    for (int i = 0; i <= 10; ++ i)
        for (int j = 0; j <= 6; ++ j)
            for (int k = 0; k <= 100; ++ k)
                for (int l = 0; l <= 6; ++ l)
                    if (j + l <= 7)
                        dp2[i + 1][j + l][k + i * l] = (dp2[i + 1][j + l][k + i * l] + 1LL * dp2[i][j][k] * get_aranj(cate[i], l)) % mod;

    int ans = 0;
    for (int i = 0; i <= 10; ++ i) {
        for (int j = i + 1; j <= 10; ++ j)
            ans = (ans + 1LL * dp2[10][6][i] * cate[j]) % mod;
    }

    for (int i = 1; i <= 6; ++ i)
        ans = (1LL * ans * i) % mod;

    cout << ans << '\n';
    return 0;
}