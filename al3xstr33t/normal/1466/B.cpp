#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, x[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &x[i]);
    for (int i=2; i<=N; i++)
        if (x[i] <= x[i - 1])
            x[i] ++;
    int ans = 1;
    for (int i=2; i<=N; i++)
        ans += (x[i] > x[i - 1]);
    printf ("%d\n", ans);
}

return 0;
}