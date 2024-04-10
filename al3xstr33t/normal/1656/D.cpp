#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 200;
long long N;

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

int brute(int n)
{
    int k = 2;
    while (k * (k - 1) / 2 <= n)
    {
        if ((n - (k * (k + 1) / 2)) % k == 0)
            return k;
        k ++;
    }
    return -1;
}

const long long INF = 1LL << 60;
long long mul(long long a, long long b)
{
    if(a == 0 || b == 0) return 0;
    if(a > INF / b) return INF;
    return 1LL *a *b;
}
long long gs(long long k)
{
    if (k % 2 == 0) return mul(k / 2, (k + 1));
    return mul((k + 1) / 2, k);
}

bool ok(long long n, long long k)
{
    return (k > 1 && gs(k) <= n && (n - gs(k)) % k == 0);
}

long long mysolve(long long n)
{
    if(n == 1) return 2;
    int k = 0;
    long long m = n;
    while (m % 2LL == 0)
        m /= 2, k ++;
    ///n = 2^k * m
    if (m == 1) return -1;
    assert(ok(n, 1LL << (k + 1)) || ok(n, m));
    if (ok(n, m)) return m;
    return 1LL << (k + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*for (int n=2; n<=1000; n++)
{
    printf ("%d ", n);
    int k1 = brute(n), k2 = mysolve(n);
    if (k1 == -1 && k2 != -1)
    {
        printf ("WA %d instead of %d\n", k2, k1);
        return 0;
    }
    else
    if (k1 != -1 && k2 == -1)
    {
        printf ("WA %d instead of %d\n", k2, k1);
        return 0;
    }
    else printf ("%2d %2d\n", k1, k2);
}
return 0;*/
int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%I64d", &N);
    printf ("%I64d\n", mysolve(N));
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/