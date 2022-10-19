#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006, M = 1000000007;

int z;
int n, m;
vector<pair<int, int> > a[N];
bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

bool c[N];
int d[N];

void bfs()
{
    queue<vector<int> > q;
    c[1] = true;
    q.push({1});
    while (!q.empty())
    {
        vector<int> x = q.front();
        q.pop();
        vector<pair<int, int> > v;
        for (int j = 0; j < x.size(); ++j)
        {
            for (int i = 0; i < a[x[j]].size(); ++i)
            {
                v.push_back(a[x[j]][i]);
            }
        }
        sort(v.begin(), v.end(), so);
        vector<int> vv;
        for (int i = 0; i < v.size(); ++i)
        {
            pair<int, int> h = v[i];
            if (i && v[i].second != v[i - 1].second)
            {
                if (!vv.empty())
                {
                    q.push(vv);
                    vv.clear();
                }
            }
            if (!c[h.first])
            {
                c[h.first] = true;
                d[h.first] = (d[x.back()] * 1LL * 10 + h.second) % M;
                vv.push_back(h.first);
            }
        }
        if (!vv.empty())
            q.push(vv);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    z = n;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vector<int> v;
        int ii = i;
        while (ii)
        {
            v.push_back(ii % 10);
            ii /= 10;
        }
        reverse(v.begin(), v.end());
        int u = x;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            a[u].push_back(m_p(++z, v[i]));
            u = z;
        }
        a[u].push_back(m_p(y, v.back()));
        u = y;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            a[u].push_back(m_p(++z, v[i]));
            u = z;
        }
        a[u].push_back(m_p(x, v.back()));
    }
    bfs();
    for (int i = 2; i <= n; ++i)
        printf("%d\n", d[i]);
    return 0;
}