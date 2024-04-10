#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009;
int N, M, ans[maxN], ap[maxN];
vector < int > v[maxN], order;

void dfs (int nod)
{
    order.push_back (nod);
    ap[nod] = order.size ();
    for (auto i : v[nod])
        if (ap[i] == 0)
            dfs (i);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests = 1;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    while (M --)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v[x].push_back (y);
        v[y].push_back (x);
    }
    order.clear ();
    dfs (1);
    if (order.size () == N)
    {
        printf ("YES\n");
        int cntTaken = 0;
        for (auto x : order)
        {
            bool any1 = 0;
            for (auto y : v[x])
                if (ap[y] < ap[x])
                    any1 |= ans[y];
            if (!any1) ans[x] = 1, cntTaken ++;
            else ans[x] = 0;
        }
        printf ("%d\n", cntTaken);
        for (int i=1; i<=N; i++)
            if (ans[i])
                printf ("%d ", i);
        printf ("\n");
    }
    else printf ("NO\n");
    for (int i=1; i<=N; i++)
        v[i].clear (), ap[i] = ans[i] = 0;
}
return 0;
}