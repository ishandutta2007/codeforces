#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N, a[maxN];
long long s[maxN];
const long long INF = 1LL << 60;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]);
    sort (a + 1, a + N + 1);
    s[0] = 0;
    for (int i=1; i<=N; i++)
        s[i] = s[i - 1] + a[i];
    if (s[N] + 1LL * a[1] * (N - 2) > 0LL || s[N] + 1LL * a[N] * (N - 2) < 0LL)
    {
        printf ("INF\n");
        continue;
    }
    if (a[1] == 0 && a[N] == 0)
    {
        printf ("0\n");
        continue;
    }
    ///a[1] < 0, a[N] > 0
    long long ans = -INF;
    for (int i=1; i<=N - 1; i++)
    {
        ///I'm assuming I have [2..i] <= -t and [i+1..N-1] > -t
        long long B = 1LL * a[1] * a[N] + 1LL * (s[i] - s[1]) * a[N] + 1LL * (s[N - 1] - s[i]) * a[1];
        long long A = s[N] + 1LL * (i - 1) * a[N] + 1LL * (N - i - 1) * a[1];
        ///max(At+b) subject to -a[i+1] < t <= -a[i]
        long long l = (i == N - 1 ? -INF : -a[i + 1]), r = (i == 1 ? INF : -a[i]);
        long long chosenT = 0;
        if (A > 0) chosenT = r;
        else chosenT = l;
        assert((chosenT != -INF && chosenT != INF) || A == 0);
        long long curr = 1LL * chosenT * A + B;
        if (curr > ans)
            ans = curr;
    }
    printf ("%I64d\n", ans);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/