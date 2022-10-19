#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    int N, z, ans;
    scanf ("%d %d", &N, &z);
    for (int i=1; i<=N; i++) {
        int x;
        scanf("%d", &x);
        if (i == 1) ans = x;
        if (x > ans)
            ans = x;
        x = x | z;
        if (x > ans)
            ans = x;
    }
    printf("%d\n", ans);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/