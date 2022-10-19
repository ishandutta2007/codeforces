#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3003;

int n, m;
vector<int> a[N];

bool c[N];
void bfs(int d[], int x)
{
    memset(c, false, sizeof c);
    queue<int> q;
    d[x] = 0;
    c[x] = true;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                d[h] = d[x] + 1;
                c[h] = true;
                q.push(h);
            }
        }
    }
}

int s1, t1, l1;
int s2, t2, l2;
int d[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);
    for (int i = 1; i <= n; ++i)
        bfs(d[i], i);
    if (l1 < d[s1][t1] || l2 < d[s2][t2])
    {
        printf("-1\n");
        return 0;
    }
    int ans = m - d[s1][t1] - d[s2][t2];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2)
                ans = max(ans, m - d[i][j] - d[i][s2] - d[i][s1] - d[j][t2] - d[j][t1]);
            swap(s1, t1);
            if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2)
                ans = max(ans, m - d[i][j] - d[i][s2] - d[i][s1] - d[j][t2] - d[j][t1]);
            swap(s1, t1);
        }
    }
    printf("%d\n", ans);
    return 0;
}