#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct ban
{
    int x;
    int i;
    long long d;
    ban(){}
    ban(int x, long long d, int i)
    {
        this->x = x;
        this->d = d;
        this->i = i;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m, k;
vector<ban> a[N];

bool c1[N];

bool c[N];
void djk()
{
    priority_queue<ban> q;
    q.push(ban(1, 0, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        c1[t.i] = true;
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            ban h = a[t.x][i];
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

vector<int> ans;

void dfs(int x, int p, int pi)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        if (m - ans.size() <= k)
            return;
        ban h = a[x][i];
        if (h.x == p) continue;
        if (c1[h.i])
        {
            dfs(h.x, x, h.i);
        }
        if (m - ans.size() <= k)
            return;
    }
    ans.push_back(pi);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(ban(y, z, i));
        a[y].push_back(ban(x, z, i));
    }
    djk();
    for (int i = 1; i <= m; ++i)
        if (!c1[i])
            ans.push_back(i);
    dfs(1, 0, 0);
    for (int i = 1; i <= m; ++i)
        c[i] = false;
    for (int i = 0; i < ans.size(); ++i)
        c[ans[i]] = true;
    cout << m - ans.size() << endl;
    for (int i = 1; i <= m; ++i)
        if (!c[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}