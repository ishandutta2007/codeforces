#include<bits/stdc++.h>

using namespace std;

const int maxN = 500009;
int N, a[maxN], ans[maxN], f[maxN];

void finish (int l, int r, int mi)
{
    for (int i=2; i<r - l + 1; i++)
        ans[i] = 0;
    ans[r - l + 1] = 1;

    ans[1] = 1;
    int L = r - l + 1;
    for (int i=0; i<L; i++)
        if (f[mi + i] != 1)
        {
            ans[1] = 0;
            break;
        }
}

void solve (int l, int r, int mi)
{
    if (f[mi] == 0)
    {
        for (int k=1; k<=r - l + 1; k++)
            ans[k] = 0;
        return ;
    }
    if (f[mi] >= 2)
    {
        ///for any 1<K<r - l + 1, ans[K] = 0
        finish (l, r, mi);
        return ;
    }
    else
    {
        if (l == r)
        {
            ans[1] = 1;
            return ;
        }
        if (a[l] != mi && a[r] != mi)
        {
            ///for any 1<K<r - l + 1, ans[K] = 0
            finish (l, r, mi);
            return ;
        }
        ans[r - l + 1] = 1;
        if (a[l] == mi)
        {
            f[mi] --;
            solve (l + 1, r, mi + 1);
        }
        else
        {
            f[mi] --;
            solve (l, r - 1, mi + 1);
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]), f[a[i]] ++;
    solve (1, N, 1);
    for (int i=1; i<=N; i++)
        f[i] = 0;
    for (int i=1; i<=N; i++)
        printf ("%d", ans[i]);
    printf ("\n");
}
return 0;
}