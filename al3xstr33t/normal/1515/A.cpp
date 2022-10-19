#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, a[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    long long x;
    scanf ("%d %I64d", &N, &x);
    long long s = 0;
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]),
        s += a[i];
    if (s == x) printf ("NO\n");
    else {
        printf ("YES\n");
        sort (a + 1, a + N + 1);
        s = 0;
        for (int i=1; i<=N; i++)
        {
            s += a[i];
            if (s == x)
            {
                assert (i < N);
                swap (a[i], a[i + 1]);
                break;
            }
        }
        for (int i=1; i<=N; i++)
            printf ("%d%c", a[i], " \n"[i == N]);
    }
}

return 0;
}