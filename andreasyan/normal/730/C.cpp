#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;

int n, m;
vector<int> a[N];

int w;
vector<pair<int, int> > v[N];

int d[N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    scanf("%d", &w);
    for (int i = 0; i < w; ++i)
    {
        int x, q, g;
        scanf("%d%d%d", &x, &q, &g);
        v[x].push_back(m_p(g, q));
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, q, g;
        scanf("%d%d%d", &x, &q, &g);
        int ans = N;
        long long gg = 0;
        long long qq = 0;
        priority_queue<pair<int, int> > u;
        memset(d, 0, sizeof d);
        queue<int> qb;
        d[x] = 1;
        qb.push(x);
        while (!qb.empty())
        {
            int x = qb.front();
            qb.pop();
            for (int i = 0; i < v[x].size(); ++i)
            {
                gg += v[x][i].first * 1LL * v[x][i].second;
                qq += v[x][i].second;
                u.push(v[x][i]);
            }
            while (qq > q)
            {
                pair<int, int> t = u.top();
                u.pop();
                if (qq - t.second >= q)
                {
                    qq -= t.second;
                    gg -= t.second * 1LL * t.first;
                }
                else
                {
                    gg -= (qq - q) * 1LL * t.first;
                    t.second -= (qq - q);
                    qq = q;
                    u.push(t);
                }
            }
            if (qq == q && gg <= g)
            {
                ans = d[x] - 1;
                break;
            }
            for (int i = 0; i < a[x].size(); ++i)
            {
                int h = a[x][i];
                if (!d[h])
                {
                    d[h] = d[x] + 1;
                    qb.push(h);
                }
            }
        }
        if (ans == N)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}