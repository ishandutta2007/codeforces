#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;

int n, k;
int a[N];

int p[N];
int q[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k * 2; ++i)
    {
        q[i] = 0;
        p[i] = 0;
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        int x = min(a[i], a[n - i + 1]);
        int y = max(a[i], a[n - i + 1]);
        p[x + 1]++;
        p[y + k + 1]--;
        q[x + y]++;
    }
    int ans = N;
    int u = 0;
    for (int i = 1; i <= k * 2; ++i)
    {
        u += p[i];
        ans = min(ans, u - q[i] + n - 2 * u);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}