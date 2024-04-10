#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int nr, ap[2 * maxN];
vector < int > v[2 * maxN];

vector < int > comp;
void dfs (int nod)
{
    ap[nod] = nr;
    comp.push_back (nod);
    for (auto it : v[nod])
        if (ap[it] == 0)
            dfs (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N, M, ans = 0;
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=M; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        if (x != y)
            v[x].push_back (y),
            v[y].push_back (x);
    }
    nr = 0;
    for (int i=1; i<=N; i++)
        if (ap[i] == 0)
        {
            nr ++, comp.clear ();
            dfs (i);
            int nodes = comp.size (), edges = 0;
            for (auto j : comp)
                for (auto k : v[j])
                    edges += (j < k);
            ans += edges;
            if (nodes == edges)
                ans ++;
        }
    for (int i=1; i<=N; i++)
        v[i].clear (), ap[i] = 0;
    printf ("%d\n", ans);
}

return 0;
}