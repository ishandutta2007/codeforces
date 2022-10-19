#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009, maxV = 1000009;
int N, Q, a[maxN], cnt[maxV + 10], msk[maxV + 10], pr[maxV + 10];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=1; i<=maxV; i++)
    msk[i] = i;
for (int i=2; i * i<=maxV; i++)
    if (pr[i] == 0)
    {
        int i2 = i * i;
        for (int j=i2; j<=maxV; j+=i)
            pr[j] = 1;
        for (int j=i2; j<=maxV; j+=i2)
        {
            while (msk[j] % i2 == 0)
                msk[j] /= i2;
        }
    }
int tests = 1;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    int ans0 = 0;
    for (int i=1; i<=N; i++)
    {
        scanf ("%d", &a[i]);
        cnt[msk[a[i]]] ++;
        if (cnt[msk[a[i]]] > ans0)
            ans0 = cnt[msk[a[i]]];
    }
    int ans = 0, all0 = 0;
    for (int i=1; i<=N; i++)
        if (cnt[msk[a[i]]] % 2 == 1 && msk[a[i]] != 1)
        {
            if (cnt[msk[a[i]]] > ans)
                ans = cnt[msk[a[i]]];
        }
        else
        {
            all0 += cnt[msk[a[i]]];
            cnt[msk[a[i]]] = 0;
        }
    ans = max (ans, all0);
    scanf ("%d", &Q);
    while (Q --)
    {
        long long w;
        scanf ("%I64d", &w);
        if (w == 0) printf ("%d\n", ans0);
        else printf ("%d\n", ans);
    }
    for (int i=1; i<=N; i++)
        cnt[msk[a[i]]] = 0;
}
return 0;
}