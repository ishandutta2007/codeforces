#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, a[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    int l = 0, r = 0, cnt0 = 0;
    for (int i=1; i<=N; i++) {
        scanf ("%d", &a[i]);
        if (a[i] > 0 && l == 0) l = i;
        if (a[i] > 0) r = i;
        cnt0 += (a[i] > 0);
    }
    if (l == 0) printf ("0\n");
    else
    if (cnt0 == 0) printf("1\n");
    else
    {
        int ans = 1;
        for (int i=l; i<=r; i++)
            if (a[i] == 0)
                ans = 2;
        printf("%d\n", ans);
    }
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/