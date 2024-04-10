#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 5003;
struct ban
{
    int x;
    int p;
    ban(){}
    ban(int x, int p)
    {
        this->x = x;
        this->p = p;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.p > b.p;
}

int n;
int b[N];
vector<pair<int, int> > a[N];
int u[N], qu[N];

void dfs(int x, int p, int qp)
{
    if (p != x)
    {
        u[x] = p;
        qu[x] = qp;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs(h, x, a[x][i].second);
    }
}

queue<ban> v[N];
priority_queue<ban> q[N];
int ans[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i < n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        q[i].push(ban(i, b[i]));
    }
    int d = 0;
    while (q[1].size() != n)
    {
        ++d;
        for (int i = 2; i <= n; ++i)
        {
            int sq = q[i].size();
            for (int j = 0; j < min(sq, qu[i]); ++j)
            {
                ban t = q[i].top();
                q[i].pop();
                if (u[i] == 1)
                    ans[t.x] = d;
                v[u[i]].push(t);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            while (!v[i].empty())
            {
                q[i].push(v[i].front());
                v[i].pop();
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}