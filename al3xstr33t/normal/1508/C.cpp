#include<bits/stdc++.h>

using namespace std;

const int maxM = 200009, maxN = 200009;
int xo, N, M, t[maxN];
bool used[maxM];
long long sum = 0;
pair < int, pair < int, int > > v[maxM];
vector < int > h[maxN], lst[maxN];

bool isEdge (int x, int y)
{
    if (x == y) return 1;
    if (x > y) swap (x, y);
    auto it = lower_bound (h[x].begin (), h[x].end (), y);
    if (it != h[x].end () && *it == y) return 1;
    return 0;
}

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

void initalizeT ()
{
    for (int i=1; i<=N; i++)
        t[i] = i;
}

set < int > S;
void dfs (int nod, int c)
{
    t[nod] = c;
    vector < int > toAdd;
    for (auto it : S)
        if (!isEdge (nod, it))
            toAdd.push_back (it);
    for (auto it : toAdd)
        S.erase (it);
    for (auto it : toAdd)
        dfs (it, c);
}

void buildSparse ()
{
    for (int i=1; i<=N; i++)
        S.insert (i);
    for (int i=1; i<=N; i++)
        if (t[i] == 0)
            S.erase (i), dfs (i, i);
}

int mat[1010][1010];
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
{
    scanf ("%d %d %d", &v[i].second.first, &v[i].second.second, &v[i].first);
    if (v[i].second.first > v[i].second.second)
        swap (v[i].second.first, v[i].second.second);
    h[v[i].second.first].push_back (v[i].second.second);
    xo ^= v[i].first;
}
for (int i=1; i<=N; i++)
    lst[i].push_back (i), sort (h[i].begin (), h[i].end ());
buildSparse ();
sort (v + 1, v + M + 1);
for (int i=1; i<=M; i++)
{
    int x = tata(v[i].second.first), y = tata(v[i].second.second);
    if (x == y) continue;
    sum += v[i].first, used[i] = 1;
    t[x] = y;
}
if (M + N - 1 < 1LL * N * (N - 1) / 2)
{
    ///this is wrong
    printf ("%I64d\n", sum);
    return 0;
}
assert (N <= 1000);
initalizeT ();
for (int i=1; i<=M; i++)
    mat[v[i].second.first][v[i].second.second] = mat[v[i].second.second][v[i].second.first] = v[i].first;
for (int i=1; i<=N; i++)
    for (int j=i + 1; j<=N; j++)
        if (mat[i][j] == 0)
        {
            int x = tata (i), y = tata (j);
            if (x == y)
            {
                printf ("%I64d\n", sum); ///found a cycle
                return 0;
            }
            t[x] = y;
        }
int minExtraEdge = 0;
initalizeT ();
for (int i=1; i<=M; i++)
{
    int x = tata(v[i].second.first), y = tata(v[i].second.second);
    if (x == y) continue;
    if (!used[i])
    {
        minExtraEdge = v[i].first;
        break;
    }
    t[x] = y;
}
if (minExtraEdge == 0 || minExtraEdge > xo) sum += xo;
else sum += minExtraEdge;
printf ("%I64d\n", sum);
return 0;
}