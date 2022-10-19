#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int t;
int q[N];

int n, m;
int x, y;
int maxu;

int qq[N];
void stg()
{
    memset(qq, 0, sizeof qq);
    y = n + m - x - maxu;
    if (!(1 <= x && x <= n && 1 <= y && y <= m))
        return;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            qq[abs(i - x) + abs(j - y)]++;
        }
    }
    for (int i = 0; i < t; ++i)
    {
        if (q[i] != qq[i])
            return;
    }
    printf("%d %d\n", n, m);
    printf("%d %d\n", x, y);
    exit(0);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        int x;
        scanf("%d", &x);
        ++q[x];
        maxu = max(maxu, x);
    }
    for (int i = 1; i < t; ++i)
    {
        if (q[i] != i * 4)
        {
            x = i;
            break;
        }
    }
    if (x == 0)
        x = 1;
    for (n = 1; n <= t; ++n)
    {
        if ((t % n) == 0)
        {
            m = t / n;
            stg();
        }
    }
    printf("-1\n");
    return 0;
}