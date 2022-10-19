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
    scanf ("%d %d %d", &N, &M, &x);
    printf ("YES\n");
    priority_queue < pair < int, int > > PQ;
    for (int i=1; i<=M; i++)
        PQ.push ({0, i});
    for (int i=1; i<=N; i++)
    {
        int h;
        scanf ("%d", &h);
        auto curr = PQ.top ();
        PQ.pop ();
        int pos = curr.second;
        PQ.push ({curr.first - h, pos});
        printf ("%d%c", pos, " \n"[i == N]);
    }
}

return 0;
}