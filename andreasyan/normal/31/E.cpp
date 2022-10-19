#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 18;

int n;
char a[N * 3];

long long ast[N * 2];
long long maxu[N * 2];
int xx[N * 2];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    ast[0] = 1;
    for (int i = 1; i < N * 2; ++i)
        ast[i] = ast[i - 1] * 10;
    for (int i = 0; i < N * 2; ++i)
        maxu[i] = -1;
    for (int x = 0; x < (1 << n); ++x)
    {
        long long yans = 0;
        int q0 = 0, q1 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                yans += ast[n - q0 - 1] * (a[i] - '0');
                ++q0;
            }
            else
            {
                yans += ast[n - q1 - 1] * (a[i] - '0');
                ++q1;
            }
        }
        if (yans > maxu[q0])
        {
            maxu[q0] = yans;
            xx[q0] = x;
        }
    }
    long long ans = -1;
    long long xxx;
    for (int x = 0; x < (1 << n); ++x)
    {
        long long yans = 0;
        int q0 = 0, q1 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (!(x & (1 << i)))
            {
                yans += ast[q0] * (a[i + n] - '0');
                ++q0;
            }
            else
            {
                yans += ast[q1] * (a[i + n] - '0');
                ++q1;
            }
        }
        if (maxu[n - q0] + yans > ans)
        {
            ans = maxu[n - q0] + yans;
            xxx = (xx[n - q0] | (((long long)x) << n));
        }
    }
    for (int i = 0; i < n * 2; ++i)
    {
        if ((xxx & (1LL << i)))
            putchar('H');
        else
            putchar('M');
    }
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}