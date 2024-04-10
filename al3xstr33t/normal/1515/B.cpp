#include<bits/stdc++.h>

using namespace std;

int N, M, x;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N;
    scanf ("%d", &N);
    if (N & 1) printf ("NO\n");
    else
    {
        N >>= 1;
        int k = 0;
        bool ok = 0;
        while (k * k <= N)
        {
            ok |= (2 * k * k == N || k * k == N);
            k ++;
        }
        if (ok) printf ("YES\n");
        else printf ("NO\n");
    }
}

return 0;
}