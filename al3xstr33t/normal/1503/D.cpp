#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N, a[maxN], b[maxN], val[2 * maxN], how[2 * maxN];

int mi[8 * maxN], ma[8 * maxN], howMi[8 * maxN], howMa[8 * maxN];
void rfrsh (int nod, int st, int dr, int mij, int f1, int f2)
{
    if (mi[f1] < mi[f2])
        mi[nod] = mi[f1], howMi[nod] = howMi[f1];
    else
        mi[nod] = mi[f2], howMi[nod] = howMi[f2];

    if (ma[f1] > ma[f2])
        ma[nod] = ma[f1], howMa[nod] = howMa[f1];
    else
        ma[nod] = ma[f2], howMa[nod] = howMa[f2];
}

void build (int nod, int st, int dr)
{
    if (st == dr) {
        howMi[nod] = howMa[nod] = how[st];
        mi[nod] = ma[nod] = val[st];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
    rfrsh (nod, st, dr, mij, f1, f2);
}

void del (int nod, int st, int dr, int pos)
{
    if (st == dr)
    {
        mi[nod] = 2 * N + 10, ma[nod] = 0;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) del (f1, st, mij, pos);
    else del (f2, mij + 1, dr, pos);
    rfrsh (nod, st, dr, mij, f1, f2);
}

int currMi, currMa, whereMi, whereMa;
void query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) currMi = mi[nod], currMa = ma[nod], whereMi = howMi[nod], whereMa = howMa[nod];
        else {
            if (mi[nod] < currMi)
                currMi = mi[nod], whereMi = howMi[nod];
            if (ma[nod] > currMa)
                currMa = ma[nod], whereMa = howMa[nod];
        }
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) query (f1, st, mij, x, y);
    if (mij < y) query (f2, mij + 1, dr, x, y);
}

vector < int > v[maxN];
bool ap[maxN];
void dfs (int i)
{
    int l = min (a[i], b[i]), r = max (a[i], b[i]);
    ap[i] = 1;
    del (1, 1, 2 * N, a[i]);
    del (1, 1, 2 * N, b[i]);
    if (r == l + 1)
        return ;
    while (1) {
        query (1, 1, 2 * N, l + 1, r - 1);
        if (currMi < l)
        {
            v[i].push_back (whereMi);
            dfs (whereMi);
        }
        else
        if (currMa > r)
        {
            v[i].push_back (whereMa);
            dfs (whereMa);
        }
        else break;
    }
}

bool type (int i, int j)
{
    if ((a[i] < a[j]) ^ (b[i] < b[j])) return 0;
    return 1;
}

int cnt[4], c[maxN];
void dfs (int nod, int t)
{
    if (c[nod] != 0)
    {
        if (c[nod] != t)
        {
            printf ("-1\n");
            exit (0);
        }
        return ;
    }
    c[nod] = t, cnt[t] ++;
    for (auto it : v[nod])
        dfs (it, type (nod, it) ? 3 - t : t);
}

int id[maxN];
bool cmp (int i, int j)
{
    return a[i] < a[j];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*int p[5];
for (int i=1; i<=4; i++)
    p[i] = i;
do {
    ///ai = p1, bi = p2, aj = p3, bj = p4
    if (max (p[1], p[2]) < min (p[3], p[4]) || max (p[3], p[4]) < min (p[1], p[2]))
        continue;
    bool canEqual = (p[1] < p[3] && p[2] > p[4]) || (p[1] > p[3] && p[2] < p[4]);
    bool canDiffer = (p[1] < p[4] && p[2] > p[3]) || (p[1] > p[4] && p[2] < p[3]);
    //assert (canEqual || canDiffer);
    if (!canEqual && !canDiffer)
    {
        printf ("WTH\n");
    }
    if (canEqual && canDiffer) printf ("FUCK\n");
    printf ("(%d, %d) (%d, %d)\n", p[1], p[2], p[3], p[4]);
}while (next_permutation (p + 1, p + 5));*/
scanf ("%d", &N);
int miMa = 2 * N + 10, maMi = 0;
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]),
    maMi = max (maMi, min (a[i], b[i])),
    miMa = min (miMa, max (a[i], b[i])),
    val[a[i]] = b[i],
    val[b[i]] = a[i], how[a[i]] = how[b[i]] = i;
if (miMa < maMi)
{
    printf ("-1\n");
    return 0;
}
build (1, 1, 2 * N);
for (int i=1; i<=N; i++)
    if (!ap[i])
        dfs (i);
int ans = 0;
for (int i=1; i<=N; i++)
    if (c[i] == 0)
    {
        cnt[1] = cnt[2] = 0;
        dfs (i, 1);
        ans += min (cnt[1], cnt[2]);
    }
for (int i=1; i<=N; i++)
{
    id[i] = i;
    if (c[i] == 2)
        swap (a[i], b[i]);
}
sort (id + 1, id + N + 1, cmp);
for (int i=1; i<N; i++)
    if (b[id[i]] < b[id[i + 1]])
    {
        printf ("-1\n");
        exit (0);
    }
printf ("%d\n", ans);
return 0;
}