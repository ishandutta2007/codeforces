#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int N, K, a[maxN], k[maxN];
long long ans;
priority_queue < pair < long long, int > > PQ;

long long f (int x, int k)
{
    int a = x / k, b = x / k + 1, timesB = x % k;
    return 1LL * b * b * timesB + 1LL * a * a * (k - timesB);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    k[i] = 1;
    if (2 <= a[i])
        PQ.push ({f (a[i], 1) - f (a[i], 2), i});
    ans += 1LL * a[i] * a[i];
}
while (K > N)
{
    auto curr = PQ.top ();
    PQ.pop ();
    ans -= curr.first;
    int i = curr.second;
    k[i] ++, K --;
    if (k[i] < a[i])
        PQ.push ({f (a[i], k[i]) - f (a[i], k[i] + 1), i});
}
printf ("%I64d\n", ans);
return 0;
}