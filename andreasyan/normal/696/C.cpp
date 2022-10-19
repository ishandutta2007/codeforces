#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
const int M = 1000000007;

long long ast(long long x, long long n)
{
    x %= M;
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
long long a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    long long u = 2;
    long long k = 1;
    for (int i = 1; i <= n; ++i)
    {
        u = ast(u, a[i]);
        if (a[i] % 2 == 0)
            k = 0;
    }
    u = (u * ast(2, M - 2)) % M;
    long long x;
    if (k == 0)
        x = ((u + 1) * ast(3, M - 2)) % M;
    else
        x = ((u - 1 + M) % M * ast(3, M - 2)) % M;
    printf("%lld/%lld\n", x, u);
    return 0;
    /*int x = 1, y = 1;
    for (int i = 0; i < 100; ++i)
    {
        printf("%d %d\n", x / 2, y / 2);
        int x1 = y - x;
        int y1 = y + y;
        x = x1;
        y = y1;
    }
    return 0;*/
}
/*
0 0
0 1
1 2
1 4
3 8
5 16
11 32
21 64
43 128
85 256
171 512
341 1024
683 2048
1365 4096
2731 8192
5461 16384
10923 32768
21845 65536
43691 131072
87381 262144
174763 524288
349525 1048576
699051 2097152
1398101 4194304
2796203 8388608
5592405 16777216
11184811 33554432
22369621 67108864
44739243 134217728
89478485 268435456
178956971 536870912
*/