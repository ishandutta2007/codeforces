#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int nr, N, M, x[2 * maxN], stk[2 * maxN], plusesBefore[2 * maxN], ans[2 * maxN];
char t[2 * maxN];
vector < pair < int, int > > v[2 * maxN];
priority_queue < pair < int, int > > PQ;

void fail ()
{
    printf ("NO\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=2 * N; i++)
{
    char blk;
    scanf ("%c%c", &t[i], &blk);
    if (t[i] == '-')
    {
        scanf ("%d\n", &x[i]);
        ///find the last x that was greater
        while (nr > 0 && x[stk[nr]] <= x[i])
            nr --;
        int lft = 1;
        if (nr > 0) lft = plusesBefore[stk[nr]] + 1;
        stk[++nr] = i;
        int rgt = M;
        //printf ("%d -> [%d %d]\n", x[i], lft, rgt);
        v[lft].push_back ({rgt, x[i]});
    }
    else M ++;
    plusesBefore[i] = M;
}
for (int i=1; i<=N; i++)
{
    for (auto it : v[i])
        PQ.push ({-it.first, it.second});
    if (PQ.empty ()) fail ();
    auto curr = PQ.top ();
    PQ.pop ();
    if (-curr.first < i) fail ();
    ans[i] = curr.second;
}
printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);
return 0;
}