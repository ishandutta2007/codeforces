#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int mod, nr, N, rmq[20][500009], ap[100009], L[100009], lg[500009], ordine[200009], T[200009], CT[200009], niv[200009], sol[200009], mars[200009], put[1000009];
vector < pair < int , int > > insus, injos, v[100009];
vector < int > fii[200009];

void dfs (int nod)
{
    ap[nod] = 1;
    rmq[0][++nr] = nod, L[nod] = nr;
    for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[it->first] == 0)
            fii[nod].push_back (it->first), T[it->first] = nod, CT[it->first] = it->second, niv[it->first] = niv[nod] + 1, dfs (it->first), rmq[0][++nr] = nod;
}

int best (int nod1, int nod2)
{
    if (niv[nod1] < niv[nod2]) return nod1;
    return nod2;
}

int Query (int Left, int Right)
{
    if (Left > Right) return Query (Right, Left);
    int p = lg[Right - Left + 1];
    return best (rmq[p][Left], rmq[p][Right - (1<<p) + 1]);
}

int Get_LCA (int a, int b)
{
    return Query (L[a], L[b]);
}

void Proces_Query (int A, int B)
{
    int lca = Get_LCA (A, B);
    insus.push_back (make_pair (A, lca));
    injos.push_back (make_pair (lca, B));
}

void Init_Rmq ()
{
    for (int i=1; (1<<i) <= nr; i++)
        for (int j=1; j + (1<<i) - 1 <= nr; j++)
            rmq[i][j] = best (rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
    for (int i=2; i<=nr; i++)
        lg[i] = lg[i>>1] + 1;
}

void Read_Queries ()
{
    int K;
    scanf ("%d", &K);
    int lst = 1, curr;
    for (int i=1; i<=K; i++)
    {
        scanf ("%d", &curr);
        Proces_Query (lst, curr);
        lst = curr;
    }
}

void Get_Order ()
{
    int nr0 = 1;
    ordine[1] = 1;
    for (int i=1; i<=nr0; i++)
        for (vector < int > :: iterator it = fii[ordine[i]].begin (); it != fii[ordine[i]].end (); it ++)
            ordine[++nr0] = *it;
}

void Expand_Mars (int val)
{
    for (int i=N; i>=1; i--)
        mars[T[ordine[i]]] += mars[ordine[i]];
    for (int i=2; i<=N; i++)
        if (CT[i] == val)
            sol[i] += mars[i];
}

void Clear_Mars ()
{
    for (int i=1; i<=N; i++)
        mars[i] = 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y, c;
    scanf ("%d %d %d", &x, &y, &c);
    if (c == 0)
        v[x].push_back (make_pair (y, 0)), v[y].push_back (make_pair (x, 0));
    else
    if (c == 1)
        v[x].push_back (make_pair (y, 1)), v[y].push_back (make_pair (x, 2));
}
////daca CT[i] = 1, atunci tata->i
////daca CT[i] = 2, atunci i->tata
dfs (1);
Init_Rmq ();
Read_Queries ();
Get_Order ();
for (vector < pair < int , int > > :: iterator it = insus.begin (); it != insus.end (); it ++)
    mars[it->first] ++, mars[it->second] --;
Expand_Mars (1);
Clear_Mars ();
for (vector < pair < int , int > > :: iterator it = injos.begin (); it != injos.end (); it ++)
    mars[it->second] ++, mars[it->first] --;
Expand_Mars (2);
//for (int i=1; i<=N; i++)
  //  printf ("%d ", sol[i]);
int ans = 0;
mod = 1e9 + 7;
put[0] = 1;
for (int i=1; i<=1000000; i++)
{
    put[i] = put[i-1] + put[i-1];
    if (put[i] >= mod) put[i] -= mod;
}
for (int i=2; i<=N; i++)
    if (sol[i] > 0)
        ans = ((long long) ans + mod - 1 + put[sol[i]]) % mod;
printf ("%d\n", ans);
return 0;
}