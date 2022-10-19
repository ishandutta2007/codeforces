#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10004, INF = 1000000009;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m, k;
vector<int> t[N], s[N];

set<pair<int, int> > c, ss;

struct ban
{
    int d;
    int x, y;
    ban(){}
    ban(int x, int y, int d)
    {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        t[x].push_back(y);
        s[y].push_back(x);
        ss.insert(m_p(x, y));
    }
    int ans = INF;
    priority_queue<ban> q;
    q.push(ban(1, 1, 0));
    while (1)
    {
        ban u;
        do
        {
            if (q.empty())
            {
                if (ans == INF)
                    printf("-1\n");
                else
                    printf("%d\n", ans);
                return 0;
            }
            u = q.top();
            q.pop();
        } while (c.find(m_p(u.x, u.y)) != c.end());
        c.insert(m_p(u.x, u.y));
        if (u.x == n && u.y == m)
            ans = min(ans, u.d);
        if (u.x == n && u.y == -1)
            ans = min(ans, u.d);
        if (u.y == m && u.x == -1)
            ans = min(ans, u.d);
        if (u.x != -1 && u.y != -1)
        {
            for (int i = 0; i < 4; ++i)
            {
                ban h = u;
                h.x += xx[i];
                h.y += yy[i];
                if (h.x >= 1 && h.x <= n && h.y >= 1 && h.y <= m && ss.find(m_p(h.x, h.y)) != ss.end())
                    q.push(h);
            }
            if (u.x - 1 >= 1)
                q.push(ban(u.x - 1, -1, u.d + 1));
            q.push(ban(u.x, -1, u.d + 1));
            if (u.x + 1 <= n)
                q.push(ban(u.x + 1, -1, u.d + 1));
            if (u.y - 1 >= 1)
                q.push(ban(-1, u.y - 1, u.d + 1));
            q.push(ban(-1, u.y, u.d + 1));
            if (u.y + 1 <= m)
                q.push(ban(-1, u.y + 1, u.d + 1));
        }
        else if (u.y == -1)
        {
            for (int i = 0; i < t[u.x - 1].size(); ++i)
            {
                q.push(ban(u.x - 1, t[u.x - 1][i], u.d));
            }
            for (int i = 0; i < t[u.x].size(); ++i)
            {
                q.push(ban(u.x, t[u.x][i], u.d));
            }
            for (int i = 0; i < t[u.x + 1].size(); ++i)
            {
                q.push(ban(u.x + 1, t[u.x + 1][i], u.d));
            }
        }
        else
        {
            for (int i = 0; i < s[u.y - 1].size(); ++i)
            {
                q.push(ban(s[u.y - 1][i], u.y - 1, u.d));
            }
            for (int i = 0; i < s[u.y].size(); ++i)
            {
                q.push(ban(s[u.y][i], u.y, u.d));
            }
            for (int i = 0; i < s[u.y + 1].size(); ++i)
            {
                q.push(ban(s[u.y + 1][i], u.y + 1, u.d));
            }
        }
    }
    return 0;
}