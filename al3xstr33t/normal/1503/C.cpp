#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N;
long long ans = 0;
pair < int, int > v[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &v[i].first, &v[i].second);
    ans += v[i].second;
    v[i].second += v[i].first;
}
sort (v + 1, v + N + 1);
int ma = v[1].second;
for (int i=2; i<=N; i++)
{
    if (ma < v[i].first) ans += v[i].first - ma;
    if (v[i].second > ma)
        ma = v[i].second;
}
printf ("%I64d\n", ans);
return 0;
}