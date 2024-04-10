#include <cstdio>
#include <iostream>

using namespace std;

inline bool GoodSolution(long long a, long long b, long long c, long long N, long long K)
{
    return (a + b + c == K && a >= 0 && b >= 0 && c >= 0 && a <= N / 3 && b <= N / 3 && c <= N / 3);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    long long T;
    scanf("%I64d", &T);

    while (T--)
    {
        long long N, K, d1, d2;
        scanf("%I64d%I64d%I64d%I64d", &N, &K, &d1, &d2);

        if (N % 3)
        {
            printf("no\n");
            continue;
        }

        bool ok = 0;

        long long a, b, c;

        //First Solution
        c = (K - 2 * d2 - d1) / 3;
        b = d2 + c;
        a = b + d1;

        if (GoodSolution(a, b, c, N, K))
            ok = 1;

        // Second Solution
        c = (K - 2 * d2 + d1) / 3;
        b = d2 + c;
        a = b - d1;

        if (GoodSolution(a, b, c, N, K))
            ok = 1;

        // Third Solution
        c = (K  + 2 * d2 - d1) / 3;
        b = c - d2;
        a = b + d1;

        if (GoodSolution(a, b, c, N, K))
            ok = 1;

        // Fouth Solution

        c = (K + 2 * d2 + d1) / 3;
        b = c - d2;
        a = b - d1;

        if (GoodSolution(a, b, c, N, K))
            ok = 1;

        if (ok) printf("yes\n");
        else printf("no\n");
    }
}