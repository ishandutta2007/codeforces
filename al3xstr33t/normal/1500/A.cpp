#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100, maxM = 2001000;
int N, M, K, a[maxN], b[maxN], ap[2 * maxM], firstPos[2 * maxM], pos[2 * maxM], cnt[2 * maxM], x[2 * maxM], y[2 * maxM];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]), ap[a[i]] ++;
    if (firstPos[a[i]] == 0)
        firstPos[a[i]] = i;
    pos[a[i]] = i;
    if (a[i] > M)
        M = a[i];
}
vector < int > vals;
for (int i=1; i<=M; i++)
{
    if (ap[i] > 0)
        b[++K] = i;
    if (ap[i] >= 4)
    {
        int cnt = 4;
        printf ("YES\n");
        for (int j=1; j<=N; j++)
            if (a[j] == i)
            {
                printf ("%d ", j);
                if (--cnt == 0)
                    break;
            }
        printf ("\n");
        return 0;
    }
    if (ap[i] >= 2)
        vals.push_back (i);
}
if (vals.size () >= 2)
{
    int x = vals[0], y = vals[1];
    printf ("YES\n%d %d %d %d\n", firstPos[x], firstPos[y], pos[x], pos[y]);
    return 0;
}
for (int i=1; i<K; i++)
{
    for (int j=i + 1; j<=K; j++)
    {
        if (++cnt[b[i] + b[j]] == 2)
        {
            printf ("YES\n%d %d %d %d\n", x[b[i] + b[j]], y[b[i] + b[j]], pos[b[i]], pos[b[j]]);
            return 0;
        }
        x[b[i] + b[j]] = pos[b[i]];
        y[b[i] + b[j]] = pos[b[j]];
    }
    if (ap[b[i]] >= 2)
    {
        if (++cnt[2 * b[i]] == 2)
        {
            printf ("YES\n%d %d %d %d\n", x[2 * b[i]], y[2 * b[i]], pos[b[i]], firstPos[b[i]]);
            return 0;
        }
        x[2 * b[i]] = firstPos[b[i]];
        y[2 * b[i]] = pos[b[i]];
    }
}
printf ("NO\n");
return 0;
}