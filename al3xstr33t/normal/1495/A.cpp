#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N;
long long x[maxN], y[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    int M = 0, K = 0;
    for (int i=1; i<=2 * N; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        if (a == 0) x[++M] = b;
        else y[++K] = a;
    }
    for (int i=1; i<=N; i++)
        x[i] = 1LL * x[i] * x[i], y[i] = 1LL * y[i] * y[i];
    sort (x + 1, x + N + 1), sort (y + 1, y + N + 1);
    double ans = 0;
    for (int i=1; i<=N; i++)
        ans = ans + sqrt (1.0 * x[i] + y[i]);
    printf ("%.15f\n", ans);
}

return 0;
}