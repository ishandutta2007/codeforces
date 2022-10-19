#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009;
int N, M, k[maxN], c[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests = 1;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        scanf ("%d", &k[i]);
    sort (k + 1, k + N + 1);
    for (int i=1; i<=M; i++)
        scanf ("%d", &c[i]);
    int i = 1, j = N;
    long long ans = 0;
    while (k[j] >= i)
        ans += c[i], i ++, j --;
    while (j > 0)
        ans += c[k[j]], j --;
    printf ("%I64d\n", ans);
}
return 0;
}