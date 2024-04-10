#include<bits/stdc++.h>

using namespace std;

const int maxN = 1009, INF = 1e6 + 100;
int N, M, d[maxN][maxN], col[maxN];
vector < int > h[maxN];
vector < pair < int, int > > v[maxN];

void addEdge (int i, int j, int c)
{
    d[i][j] = min (d[i][j], c);
    v[i].push_back ({j, c});
}

void fail ()
{
    printf ("NO\n");
    exit (0);
}

void dfs (int nod, int c)
{
    if (col[nod] != 0)
    {
        if (col[nod] != c)
            fail ();
        return ;
    }
    col[nod] = c;
    for (auto it : h[nod])
        dfs (it, 3 - c);
}

void roy ()
{
    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests = 1;
while (tests --)
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            d[i][j] = (i == j ? 0 : INF);
    while (M --)
    {
        int i, j, b;
        scanf("%d %d %d", &i, &j, &b);
        h[i].push_back (j), h[j].push_back (i);
        if (b == 0)
        {
            addEdge (i, j, 1);
            addEdge (j, i, 1);
        }
        else
        {
            ///v[j] = v[i] + 1 => v[j] <= v[i] + 1
            addEdge (i, j, 1);
            ///v[i] <= v[j] - 1
            addEdge (j, i, -1);
        }
    }
    dfs (1, 1); ///bipartiteness check
    roy ();
    for (int i=1; i<=N; i++)
        if (d[i][i] < 0)
            fail ();
    int ans = 0, mi = 1, ma = 1;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (d[i][j] > ans)
                ans = d[i][j],
                mi = i,
                ma = j;
    printf ("YES\n%d\n", ans);
    for (int i=1; i<=N; i++)
    {
        int l = d[mi][i];
        if (col[mi] == col[i] && l % 2 == 1) l ++;
        else
        if (col[mi] != col[i] && l % 2 == 0) l ++;
        printf ("%d ", l);
    }
    printf ("\n");
}
return 0;
}