#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e6 + 100;
int apL[maxN], apR[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N, L, R;
    scanf ("%d %d %d", &N, &L, &R);
    for (int i=1; i<=N; i++)
        apL[i] = apR[i] = 0;
    for (int i=1; i<=N; i++)
    {
        int x;
        scanf ("%d", &x);
        if (i <= L) apL[x] ++;
        else apR[x] ++;
    }
    if (L > R)
    {
        swap (L, R);
        for (int i=1; i<=N; i++)
            swap (apL[i], apR[i]);
    }
    int x = 0, y = 0, toOvercome = R - L, ans = 0;
    for (int i=1; i<=N; i++)
    {
        int curr = min (apL[i], apR[i]);
        apL[i] -= curr;
        apR[i] -= curr;
        while (toOvercome >= 2 && apR[i] >= 2)
            ans ++, toOvercome -= 2, apR[i] -= 2;
        x += apL[i], y += apR[i];
    }
    assert (y - x == toOvercome);
    ans += y;
    printf ("%d\n", ans);
/*    if (x > y)
        swap (x, y);
    int ans = 0;
    while (y > x)
        ans ++, y -= 2;
    assert (x == y);
    ans += x;
    printf ("%d\n", ans);*/
}

return 0;
}