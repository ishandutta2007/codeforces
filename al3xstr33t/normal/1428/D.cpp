#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int nr, N, cnt[maxN], match[maxN], stk[maxN];
bool fxd[maxN];
vector < pair < int, int > > ans;

void add (int x, int y)
{
    fxd[y] = 1;
    ans.push_back ({x, y});
}

void print ()
{
    printf ("%d\n", ans.size ());
    for (auto p : ans)
        printf ("%d %d\n", p.first, p.second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int last3 = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &cnt[i]);
    if (cnt[i] == 3) last3 = i;
}
for (int i=1; i<=N; i++)
    if (i == last3 || cnt[i] == 2)
    {
        if (cnt[i] == 2 && nr > 0 && stk[nr] == last3)
            match[last3] = i,
            stk[nr] = i;
        else
            stk[++nr] = i;
    }
    else
    if (cnt[i] == 1 && nr > 0)
    {
        match[i] = stk[nr --];
        match[match[i]] = i;
    }
if (nr > 0)
{
    printf ("-1\n");
    return 0;
}
int currL = 1, any3 = 0;
for (int i=1; i<=N; i++)
    if (cnt[i] == 3 || i == match[last3])
    {
        if (any3 == 0)
            add (currL, i), any3 = 1;
        else
            add (currL, i),
            currL ++,
            add (currL, i);
        if (cnt[i] == 2)
            add (currL, match[i]);
    }
///solved the 3s
if (any3 > 0)
    currL ++;
for (int i=1; i<=N; i++)
    if (cnt[i] == 2 && !fxd[i])
        add (currL, i),
        add (currL, match[i]),
        currL ++;
for (int i=1; i<=N; i++)
    if (cnt[i] == 1 && !fxd[i])
        add (currL, i),
        currL ++;
print ();
return 0;
}