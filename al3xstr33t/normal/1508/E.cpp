#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009, maxLog = 20;
int sons[maxN], t[maxN], p[maxN], pos[maxN], lev[maxN], N;
bool active[maxN], everActive[maxN];
long long sum = 0;
vector < int > v[maxN], ans[maxN];
bool DBG;

void dfs (int nod)
{
    for (auto it : v[nod])
        lev[it] = lev[nod] + 1, dfs (it);
}

void fail (int x)
{
    printf ("NO\n");
    if (DBG)
        printf ("%d\n", x);
    exit (0);
}

int nr = 0, ord[maxN];
void dfs2 (int nod)
{
    ord[nod] = ++nr;
    for (auto it : ans[nod])
        dfs2 (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]), pos[p[i]] = i;
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    t[y] = x;
    v[x].push_back (y), sons[x] ++;
}
t[1] = -1, lev[1] = 0, dfs (1);
vector < int > stk;
int q = 1, prv = -1;
long long time = 0;
while (q <= N)
{
    int node = pos[q];
    time += lev[node];
    {
        vector < int > rv;
        int aux = node;
        while ((prv == -1 || aux != t[prv]) && aux != -1)
            rv.push_back (aux),
            aux = t[aux];
        if (q != 1 && aux != t[prv])
        {
            if (sons[node] > 0)
            {
                int aux = node;
                while (aux != -1)
                {
                    if (!active[aux])
                        fail (2);
                    aux = t[aux];
                }
            }
            else fail (1);
        }
        if (aux != -1)
            rv.push_back (aux);
        everActive[node] = 1;
        if (rv.size () > 1 && (q == 1 || aux == t[prv]))
        {
            for (int i=rv.size () - 1; i>0; i--)
                ans[rv[i]].push_back (rv[i - 1]),
                active[rv[i]] = 1, everActive[rv[i]] = 1;
        }
        else active[node] = 0;
        if (sons[node] > 0)
        {
            while (node != 1)
                swap (p[t[node]], p[node]),
                node = t[node];
            break;
        }
    }
    prv = node;
    if (t[node] != -1)
        sons[t[node]] --;
    q ++;
}
for (int i=1; i<=N; i++)
{
    vector < int > curr;
    for (auto j : v[i])
        if (!everActive[j])
            curr.push_back (j);
    sort (curr.begin (), curr.end (), [](int i, int j) {return p[i] < p[j];});
    for (auto it : curr)
        ans[i].push_back (it);
}
dfs2 (1);
if (DBG) {
    for (int i=1; i<=10; i++)
        printf ("%d ", ord[i]);
    printf ("\n");
}
for (int i=1; i<=N; i++)
    if (!everActive[i] && p[i] != ord[i])
        fail (3);
active[pos[q]] = 1;
for (int i=2; i<=N; i++)
    if (active[i] && p[i] < p[t[i]])
        fail (4);
printf ("YES\n%I64d\n", time);
for (int i=1; i<=N; i++)
    printf ("%d ", ord[i]);
printf ("\n");
return 0;
}