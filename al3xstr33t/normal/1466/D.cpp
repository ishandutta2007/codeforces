#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, cnt[maxN];
pair < int , int > w[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
while (tests --)
{
    scanf ("%d", &N);
    long long ans = 0;
    for (int i=1; i<=N; i++)
        scanf ("%d", &w[i].first),
        ans += w[i].first,
        w[i].first = -w[i].first,
        w[i].second = i;
    for (int i=1; i<N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        cnt[x] ++, cnt[y] ++;
    }
    sort (w + 1, w + N + 1);
    int i = 1;
    for (int k=1; k<N; k++)
    {
        printf ("%I64d%c", ans, " \n"[k == N - 1]);
        while (i <= N && cnt[w[i].second] <= 1)
            i ++;
        ans -= w[i].first;
        cnt[w[i].second] --;
    }
    for (int i=1; i<=N; i++)
        cnt[i] = 0;
}

return 0;
}