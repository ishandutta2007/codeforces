#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009, maxM = maxN;
int N, M, t[maxM], sz[maxM], edges[maxM], e[maxM], take[maxN];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}

int tata (int nod)
{
    if (t[nod] == nod) return nod;
    int x = tata (t[nod]);
    e[nod] ^= e[t[nod]];
    t[nod] = x;
    return x;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    t[i] = i, sz[i] = 1, edges[i] = 0;
int ans = 1, e2 = 0;
for (int i=1; i<=N; i++)
{
    int k, x, y;
    scanf ("%d", &k);
    if (k == 1)
        scanf ("%d", &x), y = x;
    else
        scanf ("%d %d", &x, &y);
    int a = tata (x), b = tata (y);
    if (a == b)
    {
        if (x == y && edges[a] < sz[a])
            edges[a] ++, take[i] = 1;
    }
    else
    if (edges[a] < sz[a] || edges[b] < sz[b])
    {
        ///a becomes father of b
        edges[a] ++, edges[a] += edges[b], sz[a] += sz[b];
        t[b] = a, e[b] = 1 ^ e[x] ^ e[y];
        take[i] = 1;
    }
    if (take[i])
        e2 ++, ans = add (ans, ans);
}
printf ("%d %d\n", ans, e2);
for (int i=1; i<=N; i++)
    if (take[i])
        printf ("%d ", i);
printf ("\n");
return 0;
}