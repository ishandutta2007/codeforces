#include<bits/stdc++.h>

using namespace std;

const int maxN = 500009;
int N, a[maxN], f[maxN];

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
        scanf ("%d", &a[i]);
    int worst = 0, K = 0;
    for (int i=1; i<=N; i++)
    {
        int j = i;
        while (j < N && a[j + 1] != a[j])
            j ++;
        ///[i, j]
        K ++;
        f[a[i]] ++;
        if (f[a[i]] > f[worst])
            worst = a[i];
        f[a[j]] ++;
        if (f[a[j]] > f[worst])
            worst = a[j];
        ///
        i = j;
    }

    if (worst != 0 && f[worst] > K + 1)
    {
        int fGood = 0;
        for (int i=1; i<N; i++)
            if (a[i] != a[i + 1] && a[i] != worst && a[i + 1] != worst)
                fGood ++;
        while (fGood > 0 && f[worst] > K + 1)
            fGood --,
            K ++;
    }

    if (worst != 0 && f[worst] > K + 1) printf ("-1\n");
    else printf ("%d\n", K - 1);

    for (int i=1; i<=N; i++)
        f[i] = 0;
}
return 0;
}