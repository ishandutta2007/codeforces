#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int x, d;
    ban()
    {
        x = d = 0;
    }
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m;
vector<ban> a[N];

vector<int> v[N];
map<int, int> mp[N];

bool c[N];
int djk()
{
    priority_queue<ban> q;
    if (mp[1].find(0) != mp[1].end())
        q.push(ban(1, mp[1][0]));
    else
        q.push(ban(1, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return -1;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        if (t.x == n)
            return t.d;
        c[t.x] = true;
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            ban h = a[t.x][i];
            h.d += t.d;
            if (!c[h.x])
            {
                if (mp[h.x].find(h.d) != mp[h.x].end())
                    h.d = mp[h.x][h.d];
                q.push(h);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(ban(y, z));
        a[y].push_back(ban(x, z));
    }
    for (int i = 1; i <= n; ++i)
    {
        int m;
        scanf("%d", &m);
        while (m--)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    v[n].clear();
    for (int i = 1; i <= n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        for (int j = v[i].size() - 1; j >= 0; --j)
        {
            if (j == v[i].size() - 1 || v[i][j] + 1 != v[i][j + 1])
                mp[i][v[i][j]] = v[i][j] + 1;
            else
                mp[i][v[i][j]] = mp[i][v[i][j + 1]];
        }
    }
    printf("%d\n", djk());
    return 0;
}