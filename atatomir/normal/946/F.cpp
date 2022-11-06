#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 103;
const int mod = 1000000007;

int n, x, i, l, r, k, aux;
char s[maxN];
int dp[maxN][maxN][maxN];
int sz[maxN];

void add(int& a, int b, int modulo = mod) {
    a += b;
    if (a >= modulo) a -= modulo;
}

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s", &n, &x, s + 1);
    for (i = 1; i <= n; i++) {
        if (s[i] == '0')
            dp[0][i][i] = 1;
        else
            dp[1][i][i] = 1;
    }

    sz[0] = sz[1] = 1;
    for (i = 2; i <= x; i++) {
        sz[i] = sz[i - 1];
        add(sz[i], sz[i - 2], mod - 1);
    }

    for (i = 2; i <= x; i++) {
        for (l = 1; l <= n; l++) {
            for (r = l; r <= n; r++) {
                //! only right
                aux = (l == 1 ? poww(2, sz[i - 1]) : 1);
                add(dp[i][l][r], (1LL * dp[i - 2][l][r] * aux) % mod);

                //! only left
                aux = (r == n ? poww(2, sz[i - 2]) : 1);
                add(dp[i][l][r], (1LL * dp[i - 1][l][r] * aux) % mod);

                //! split
                for (k = l; k < r; k++) {
                    add(dp[i][l][r], (1LL * dp[i - 1][l][k] * dp[i - 2][k + 1][r]) % mod);
                }
            }
        }
    }

    printf("%d", dp[x][1][n]);


    return 0;
}