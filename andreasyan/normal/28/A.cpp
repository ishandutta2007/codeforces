#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m;
int x[N], y[N];
int d[N];
queue<int> q[N];

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int ans[N];
bool stg(int s)
{
    for (int i = 1; i <= m; ++i)
    {
        while (!q[d[i]].empty())
            q[d[i]].pop();
    }
    for (int i = 1; i <= m; ++i)
        q[d[i]].push(i);
    for (int i = 0; i < n; ++i)
        ans[i] = -1;
    for (int i = s; i < n; i += 2)
    {
        int dd = dist(x[i], y[i], x[(i - 1 + n) % n], y[(i - 1 + n) % n]) +
            dist(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
        if (q[dd].empty())
            return false;
        ans[i] = q[dd].front();
        q[dd].pop();
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &d[i]);
    }
    if (stg(0))
    {
        printf("YES\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else if (stg(1))
    {
        printf("YES\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else
        printf("NO\n");
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