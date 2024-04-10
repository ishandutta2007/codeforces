#include<bits/stdc++.h>

using namespace std;

int N, K;
const int maxN = 1e6 + 200;
int a[maxN];

/*int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
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
}*/

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
while (tests --)
{
    scanf ("%d", &N);
    bool ok = 0, any1 = 0, any0 = 0;
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]), any1 |= (a[i] == 1), any0 |= (a[i] == 0);
    if (!any1) ok = 1;
    else
    if (!any0) {
        ok = 1;
        sort (a + 1, a + N + 1);
        for (int i=2; i<=N; i++)
            if (a[i] - a[i - 1] == 1)
                ok = 0;
    }
    if (ok) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/