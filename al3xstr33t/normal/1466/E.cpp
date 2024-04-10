#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009, B = 61;
int N, cnt[B + 10], p2[B + 10];
long long x[maxN];

const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
p2[0] = 1;
for (int i=1; i<B; i++)
    p2[i] = add (p2[i - 1], p2[i - 1]);
while (tests --)
{
    scanf ("%d", &N);
    memset (cnt, 0, sizeof (cnt));
    for (int i=1; i<=N; i++)
    {
        scanf ("%I64d", &x[i]);
        for (int j=0; j<B; j++)
            if (x[i] & (1LL << j))
                cnt[j] ++;
    }
    int ans = 0;
    for (int i=1; i<=N; i++)
    {
        int nd = 0, r = 0;
        for (int j=0; j<B; j++)
        {
            if (x[i] & (1LL << j))
                adto (nd, mul (p2[j], cnt[j])),
                adto (r, mul (p2[j], N));
            else
                adto (r, mul (p2[j], cnt[j]));
        }
        adto (ans, mul (nd, r));
    }
    printf ("%d\n", ans);
}

return 0;
}