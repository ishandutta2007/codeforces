#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009, maxM = 300009;
int N, M, X, posJ[maxN], a[maxN], t[maxN], x[maxM], y[maxM];
long long vol[maxN];
vector < int > v[maxN], h[maxN];
int pos[maxN];
queue < int > cc;

void doMerge (int c1, int c2)
{
    if (h[c1].size () > h[c2].size ())
        swap (c1, c2);
    for (auto i : h[c1])
        h[c2].push_back (i),
        t[i] = c2;
    vol[c2] += vol[c1] - X;
    assert (vol[c2] >= 0);
    vector < int > curr;
    swap (h[c1], curr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &X);
long long s = 0;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]),
    s += a[i];
if (s < 1LL * (N - 1) * X)
{
    printf ("NO\n");
    return 0;
}
for (int i=1; i<=M; i++)
    scanf ("%d %d", &x[i], &y[i]),
    v[x[i]].push_back (i),
    v[y[i]].push_back (i);
printf ("YES\n");
for (int i=1; i<=N; i++)
{
    t[i] = i, vol[i] = a[i], h[i].push_back (i);
    pos[i] = 0, posJ[i] = 0;
    if (vol[i] >= X)
        cc.push (i);
}
int steps = N - 1;
while (!cc.empty () && steps > 0)
{
    int root = cc.front ();
    cc.pop ();
    if (vol[root] < X || t[root] != root)
        continue;
    int foundK = -1, edge = -1;
    while (posJ[root] < h[root].size ())
    {
        int j = h[root][posJ[root]];
        while (pos[j] < v[j].size ())
        {
            int k = v[j][pos[j]];
            k = x[k] ^ y[k] ^ j;
            pos[j] ++;
            if (t[k] != root)
            {
                edge = v[j][pos[j] - 1];
                foundK = k;
                break;
            }
        }
        if (foundK != -1)
            break;
        posJ[root] ++;
    }
    assert (foundK != -1);
    int bef = vol[t[foundK]];
    printf ("%d\n", edge);
    doMerge (root, t[foundK]);
    steps --;
    if (t[root] == root && vol[root] >= X)
        cc.push (root);
    else
    if (t[root] == t[foundK] && vol[t[root]] >= X && bef < X)
        cc.push (t[root]);
}
if (steps > 0)
{
    ///at this point I can merge anything and it'll be fine
    for (int i=1; i<=M; i++)
        if (t[x[i]] != t[y[i]])
        {
            printf ("%d\n", i);
            assert (vol[t[x[i]]] + vol[t[y[i]]] >= X);
            doMerge (t[x[i]], t[y[i]]);
        }
}
return 0;
}