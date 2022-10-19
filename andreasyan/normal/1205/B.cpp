#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
const int m = 60;

int n;
long long a[N];

int ans = N;

vector<int> v[m];

set<pair<int, int> > s;

vector<int> g[N];

bool c[N];
int bfs(int x, int y)
{
    vector<int> v;
    queue<pair<int, int> > q;
    c[x] = true;
    v.push_back(x);
    q.push(m_p(x, 0));
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        if (t.first == y)
        {
            for (int i = 0; i < v.size(); ++i)
                c[v[i]] = false;
            return t.second;
        }
        for (int i = 0; i < g[t.first].size(); ++i)
        {
            pair<int, int> h = m_p(g[t.first][i], t.second + 1);
            if (!c[h.first])
            {
                c[h.first] = true;
                v.push_back(h.first);
                q.push(h);
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
        c[v[i]] = false;
    return N;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (long long j = 0; j < m; ++j)
        {
            if ((a[i] & (1LL << j)))
                v[j].push_back(i);
        }
    }
    for (int j = 0; j < m; ++j)
    {
        if (v[j].size() >= 3)
        {
            printf("3\n");
            return 0;
        }
    }
    for (int j = 0; j < m; ++j)
    {
        if (v[j].size() == 2)
        {
            int minu = min(v[j][0], v[j][1]);
            int maxu = max(v[j][0], v[j][1]);
            s.insert(m_p(minu, maxu));
        }
    }
    for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it)
    {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (set<pair<int, int> >::iterator it1 = s.begin(); it1 != s.end(); ++it1)
        {
            if (it1 == it)
                continue;
            g[it1->first].push_back(it1->second);
            g[it1->second].push_back(it1->first);
        }
        ans = min(ans, 1 + bfs(it->first, it->second));
    }
    if (ans == N)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}