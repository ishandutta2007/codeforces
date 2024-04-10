#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009, maxM = 300009;
int N, M, ap[maxN];
long long per[maxN], lev[maxN];
vector < pair < int, int > > v[maxN], h[maxN];

long long gcdL (long long a, long long b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    long long r = 0;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

vector < int > nodes;
void dfs (int nod)
{
    ap[nod] = 1;
    for (auto it : h[nod])
        if (!ap[it.first])
            dfs (it.first);
    nodes.push_back (nod);
}

vector < int > comp;
void dfp (int nod)
{
    ap[nod] = 2;
    comp.push_back (nod);
    for (auto it : v[nod])
        if (ap[it.first] == 1)
            lev[it.first] = lev[nod] + it.second,
            dfp (it.first);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
{
    int x, y, z;
    scanf ("%d %d %d", &x, &y, &z);
    v[x].push_back ({y, z});
    h[y].push_back ({x, z});
}
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
        dfs (i);
reverse (nodes.begin (), nodes.end ());
for (auto i : nodes)
    if (ap[i] == 1)
    {
        comp.clear ();
        dfp (i);
        long long currPeriod = 0;
        for (auto j : comp)
            for (auto k : v[j])
            if (ap[k.first] == 2)
            {
                ///lev[j] + k.second = lev[k.first]
                long long curr = lev[k.first] - lev[j] - k.second;
                //printf ("%d -> %d  -- %I64d\n", j, k.first, curr);
                currPeriod = gcdL (currPeriod, curr);
            }
        for (auto j : comp)
            per[j] = currPeriod,
            ap[j] = 0;
            //printf ("%d -> %I64d\n", j, per[j]);
        if (comp.size () == 1)
        {
            for (auto j : comp)
                per[j] = -1; ///not contained in a cycle
        }
    }
int Q;
scanf ("%d", &Q);
while (Q --)
{
    int v, s, t;
    scanf ("%d %d %d", &v, &s, &t);
    long long k = per[v];
    if (k == -1)
    {
        if (s == 0) printf ("YES\n");
        else printf ("NO\n");
    }
    else
    {
        s = t - s; ///want x divisible by k to be = s mod t
        long long d = gcdL (k, t);
        if (s % d == 0) printf ("YES\n");
        else printf ("NO\n");
    }
}
return 0;
}