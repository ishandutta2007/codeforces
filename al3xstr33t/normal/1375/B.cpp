#include<bits/stdc++.h>

using namespace std;

int countNeighbours (int i, int j, int N, int M)
{
    return (i > 1) + (j > 1) + (i < N) + (j < M);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, N, M;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    bool ok = 1;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        {
            int x;
            scanf ("%d", &x);
            if (x > countNeighbours (i, j, N, M))
                ok = 0;
        }
    if (ok)
    {
        printf ("YES\n");
        for (int i=1; i<=N; i++, printf ("\n"))
            for (int j=1; j<=M; j++)
                printf ("%d ", countNeighbours (i, j, N, M));
    }
    else
        printf ("NO\n");
}

return 0;
}