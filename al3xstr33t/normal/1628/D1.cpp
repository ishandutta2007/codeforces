#include<bits/stdc++.h>

using namespace std;

const int maxN = 2020;
int N, M, K, dp[maxN][maxN];
double dpr[maxN][maxN];
const double eps = 1e-8;
const int mod = 1e9 + 7;

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

int div2 (int x)
{
    if (x & 1) x += mod;
    return x >> 1;
}

/*int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/


int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
//N = 2001, K = 1;
N = 2001, K = 1;
dp[0][0] = 0, dpr[0][0] = 0;
for (int i=1; i<=N; i++)
{
    dp[i][0] = dp[i - 1][0], dpr[i][0] = dpr[i - 1][0];
    dp[i][i] = mul (i, K), dpr[i][i] = 1.0 * i * K;
    for (int j=1; j<i; j++)
    {
        /*if (dpr[i - 1][j - 1] - eps > dp[i - 1][j])
        {
            printf("fuck (%d, %d) : %.10f %.10f\n", i, j, dp[i - 1][j - 1], dp[i - 1][j]);
            return 0;
        }
        assert (dpr[i - 1][j - 1] - eps <= dp[i - 1][j]);
        if (dpr[i - 1][j] - 2.0 * K > dpr[i - 1][j - 1]) {
            fprintf(stderr, "got here %d %d\n", i, j);
            dpr[i][j] = dpr[i - 1][j - 1] + K, dp[i][j] = add (dp[i - 1][j - 1], K);
        }
        else*/
            dpr[i][j] = 0.5 * (dpr[i - 1][j] + dpr[i - 1][j - 1]), dp[i][j] = div2 (add (dp[i - 1][j - 1], dp[i - 1][j]));
    }
}
/*for (int i=1; i<=20; i++, printf("\n"))
    for (int j=0; j<=i; j++)
        printf ("%.5f ", dpr[i][j]);*/
while (tests --)
{
    //printf ("Case #%d: ", ++testId);
    scanf ("%d %d %d", &N, &M, &K);
    printf("%d\n", mul (K, dp[N][M]));
    //printf("%d %.5f\n", dp[N][M], dpr[N][M]);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/