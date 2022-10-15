#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 50000;
const long long INF = (long long)1e+18;

int a[MAXN];
int n, m;
long long low, high;


int check(int x, int y, int z)
{
    long long v = (long long)x * (long long)y * (long long)z;
    low = min(v, low);
    high = max(v, high);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            a[m++] = i;
            if (i * i < n)
                a[m++] = n / i;
        }
    sort(a, a + m);

    low = INF;
    high = -INF;
    for (int i = 0; i < m; i++)
        for (int j = 1; j * j <= a[i]; j++)
            if (a[i] % j == 0)
            {
                check(j + 1, a[i] / j + 2, n / a[i] + 2);
                check(j + 2, a[i] / j + 1, n / a[i] + 2);
                check(j + 2, a[i] / j + 2, n / a[i] + 1);
            }
    cout << low - n << " " << high - n << endl;
    return 0;
}