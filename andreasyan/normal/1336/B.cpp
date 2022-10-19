#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const long long INF = 2000000000000000009;

int n[3];
int a[3][N];

void solv()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d", &n[i]);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
            scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < 3; ++i)
    {
        sort(a[i], a[i] + n[i]);
    }
    int u[3] = {0, 1, 2};
    long long ans = INF;
    do
    {
        for (int i = 0; i < n[u[0]]; ++i)
        {
            int j = lower_bound(a[u[1]], a[u[1]] + n[u[1]], a[u[0]][i]) - a[u[1]];
            if (j == n[u[1]])
                continue;
            int k = upper_bound(a[u[2]], a[u[2]] + n[u[2]], a[u[0]][i]) - a[u[2]] - 1;
            if (k == -1)
                continue;
            long long x = a[u[0]][i];
            long long y = a[u[1]][j];
            long long z = a[u[2]][k];
            ans = min(ans, (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x));
        }
    } while (next_permutation(u, u + 3));
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}