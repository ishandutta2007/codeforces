#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n, m, dx, dy;
int q[N];
int qq[N];

int main()
{
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        q[x] = i;
        x = (x + dx) % n;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int sy = (y - (dy * 1LL * q[x]) % n + n) % n;
        qq[sy]++;
    }
    int maxu = 0;
    for (int sy = 0; sy < n; ++sy)
        maxu = max(maxu, qq[sy]);
    for (int sy = 0; sy < n; ++sy)
    {
        if (qq[sy] == maxu)
        {
            printf("%d %d\n", 0, sy);
            return 0;
        }
    }
    return 0;
}