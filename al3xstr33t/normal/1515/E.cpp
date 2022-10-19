#include<bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int N, mod, ways[maxN], dp[maxN][maxN];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &mod), Prec (4 * N + 10);
ways[1] = 1;
for (int i=2; i<=N; i++)
    for (int j=1; j<=i; j++)
        adto (ways[i], comb (j - 1 + (i - j), j - 1));
for (int i=1; i<=N; i++)
    ways[i] = mul (ways[i], inv[i]);
for (int i=1; i<=N; i++)
    dp[1][i] = ways[i];
for (int i=1; i<N; i++)
    for (int j=0; j<=N; j++)
        for (int k=1; j + k <= N; k++)
            adto (dp[i + 1][j + k], mul (dp[i][j], ways[k]));
int ans = 0;
for (int i=0; i<=N; i++)
{
    ///suppose I have i determined points, then the sum of the in-between lengths will be N - i, and will be divided
    ///in i + 1 blocks
    if (N - i >= i + 1)
        adto (ans, mul (dp[i + 1][N - i], fac[N - i]));
}
printf ("%d\n", ans);
return 0;
}