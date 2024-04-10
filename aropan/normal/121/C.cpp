#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXF = 20;


long long f[MAXF];

int a[MAXF];
int p[MAXF];

bool isLucky(long long x)
{
    do if (x % 10 != 4 && x % 10 != 7) return false; while (x /= 10);
    return true;
}

long long count(long long n)
{
    long long res = 0;;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < (1 << i); j++)
        {
            long long x = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                (x *= 10) += 4;
                if (j & (1 << k)) x += 3;
            }

            if (x > n) return res;
            res++;
        }
    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    long long n, m, k;
    scanf("%I64d %I64d", &n, &k);


    f[0] = 1;
    for (int i = 1; i < MAXF; i++)
        f[i] = f[i - 1] * i;

    for (m = 0; k > f[m]; m++);


    if (m > n)
    {
        puts("-1");
        return 0;
    }

    n -= m;
    long long ans = count(n);

    k--;
    for (int i = 0; i < m; i++) a[i] = i;
    for (int i = 0; i < m; i++)
    {
        int t = k / f[m - i - 1];
        k %= f[m - i - 1];

        p[i] = a[t];
        for (int j = t; j < m - i; j++)
            a[j] = a[j + 1];
    }


    for (int i = 0; i < m; i++)
    {
//        printf("%I64d %I64d\n", n + i + 1, n + p[i] + 1);
        if (isLucky(n + i + 1) && isLucky(n + p[i] + 1)) ans++;
    }

    printf("%I64d\n", ans);
    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}