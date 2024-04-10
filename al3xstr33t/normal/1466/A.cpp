#include<bits/stdc++.h>

using namespace std;

int N, x[100];

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
    set < int > S;
    for (int i=1; i<N; i++)
        for (int j=i + 1; j<=N; j++)
            S.insert (x[j] - x[i]);
    printf ("%d\n", S.size ());
}

return 0;
}