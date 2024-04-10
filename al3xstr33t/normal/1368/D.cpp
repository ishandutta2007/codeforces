#include<bits/stdc++.h>

using namespace std;

const int M = 20;
int N, cnt[(1 << M) + 10], ans[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    cnt[x] ++;
}
for (int i=0; i<M; i++)
    for (int j=0; j<(1 << M); j++)
        if ((j & (1 << i)) == 0)
            cnt[j] += cnt[j ^ (1 << i)];
for (int i=0; i<(1 << M); i++)
    ans[cnt[i]] |= i;
for (int i=N - 1; i>=1; i--)
    ans[i] |= ans[i + 1];
long long s = 0;
for (int i=1; i<=N; i++)
    s += 1LL * ans[i] * ans[i];
printf ("%lld\n", s);
return 0;
}