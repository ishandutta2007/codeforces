#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int K, N, x[maxN], y[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &K);
    for (int i=1; i<=N; i++)
        scanf ("%d %d", &x[i], &y[i]);
    int ans = -1;
    for (int i=1; i<=N; i++)
    {
        bool ok = 1;
        for (int j=1; j<=N; j++)
            if (abs (x[i] - x[j]) + abs (y[i] - y[j]) > K)
            {
                ok = 0;
                break;
            }
        if (ok)
            ans = 1;
    }
    printf ("%d\n", ans);
}
return 0;
}