#include<bits/stdc++.h>

using namespace std;

int tests, N;

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
    {
        int x;
        scanf ("%d", &x);
        if (x < 0)
            x = -x;
        if (i & 1)
            x = -x;
        printf ("%d ", x);
    }
    printf ("\n");
}

return 0;
}