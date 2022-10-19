#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
int a[N];

int ans[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    long long s = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (i - 1 + a[i] > n)
        {
            printf("-1\n");
            return;
        }
        s += a[i];
    }
    if (s < n)
    {
        printf("-1\n");
        return;
    }
    int u = n + 1;
    for (int i = m; i >= 1; --i)
    {
        if (u - a[i] > i - 1)
        {
            ans[i] = u - a[i];
            u -= a[i];
            continue;
        }
        ans[i] = i;
        u = i;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}