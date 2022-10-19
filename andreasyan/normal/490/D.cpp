#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const long long INF = 1000000009;
struct ban
{
    long long x, y;
    ban()
    {
        x = y = 0;
    }
    ban(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
};

map<long long, map<long long, long long> > da, db;

map<long long, ban> aa, bb;

void bfs(ban a, map<long long, map<long long, long long> >& d, map<long long, ban>& gg)
{
    queue<ban> q;
    q.push(a);
    d[a.x][a.y] = 0;
    while (!q.empty())
    {
        ban a = q.front();
        q.pop();
        if (gg.find(a.x * a.y) == gg.end())
            gg[a.x * a.y] = a;
        if (a.x % 2 == 0 && d[a.x / 2].find(a.y) == d[a.x / 2].end())
        {
            d[a.x / 2][a.y] = d[a.x][a.y] + 1;
            q.push(ban(a.x / 2, a.y));
        }
        if (a.x % 3 == 0 && d[a.x / 3 * 2].find(a.y) == d[a.x / 3 * 2].end())
        {
            d[a.x / 3 * 2][a.y] = d[a.x][a.y] + 1;
            q.push(ban(a.x / 3 * 2, a.y));
        }
        if (a.y % 2 == 0 && d[a.x].find(a.y / 2) == d[a.x].end())
        {
            d[a.x][a.y / 2] = d[a.x][a.y] + 1;
            q.push(ban(a.x, a.y / 2));
        }
        if (a.y % 3 == 0 && d[a.x].find(a.y / 3 * 2) == d[a.x].end())
        {
            d[a.x][a.y / 3 * 2] = d[a.x][a.y] + 1;
            q.push(ban(a.x, a.y / 3 * 2));
        }
    }
}

long long ans = INF;
ban ansa, ansb;

int main()
{
    ban a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;

    bfs(a, da, aa);
    bfs(b, db, bb);

    for (map<long long, ban>::iterator it = aa.begin(); it != aa.end(); ++it)
    {
        if (bb.find(it->first) != bb.end())
        {
            if (da[it->second.x][it->second.y] + db[bb[it->first].x][bb[it->first].y] < ans)
            {
                ans = da[it->second.x][it->second.y] + db[bb[it->first].x][bb[it->first].y];
                ansa = it->second;
                ansb = bb[it->first];
            }
        }
    }

    if (ans == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    cout << ansa.x << ' ' << ansa.y << endl;
    cout << ansb.x << ' ' << ansb.y << endl;
    return 0;
}