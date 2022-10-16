#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int MOD = 1000000000 + 7;

int raise(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * raise(a, b - 1)) % MOD;
    else {
        int aux = raise(a, b >> 1);
        return (1LL * aux * aux) % MOD;
    }
}
inline int getInv(int nr) {
    return raise(nr, MOD - 2);
}

const int NMAX = 1020 + 5;

int dp[NMAX][NMAX];

int main()
{
    int K, x, y;
    cin >> K >> x >> y;

    const int iv = getInv(x + y);
    const int pA = (1LL * x * iv) % MOD;
    const int pB = (1LL * y * iv) % MOD;

    const int invPB = getInv(pB);
    for (int a = K; a; -- a) {
        for (int k = 0; k <= a; ++ k)
            dp[a][k] = (a - 1 + invPB) % MOD;
        for (int k = a + 1; k <= K; ++ k) {
            // Am a 'A'-uri si mai am de facut k chesti
            dp[a][k] = (1LL * pA * dp[a + 1][k] + 1LL * pB * (a + dp[a][k - a])) % MOD;
        }
    }

    cout << dp[1][K] << '\n';
    return 0;
}