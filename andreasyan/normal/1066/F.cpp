#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1000000000000000018;
#define int long long
struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

set<int> s;
map<int, ban> l;
map<int, ban> r;

map<int, pair<long long, long long> > dp;

long long dist(ban a, ban b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void ubd(long long q, ban t, int x)
{
    dp[x].first = min(dp[x].first, q + dist(t, r[x]) + dist(r[x], l[x]));
    dp[x].second = min(dp[x].second, q + dist(t, l[x]) + dist(l[x], r[x]));
}

int32_t main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ban t;
        cin >> t.x >> t.y;
        if (l.find(max(t.x, t.y)) == l.end())
            l[max(t.x, t.y)] = t;
        else
        {
            if (t.x < l[max(t.x, t.y)].x)
                l[max(t.x, t.y)] = t;
            else if (t.x == l[max(t.x, t.y)].x)
            {
                if (t.y > l[max(t.x, t.y)].y)
                    l[max(t.x, t.y)] = t;
            }
        }
        if (r.find(max(t.x, t.y)) == r.end())
            r[max(t.x, t.y)] = t;
        else
        {
            if (t.y < r[max(t.x, t.y)].y)
                r[max(t.x, t.y)] = t;
            else if (t.y == r[max(t.x, t.y)].y)
            {
                if (t.x > r[max(t.x, t.y)].x)
                    r[max(t.x, t.y)] = t;
            }
        }
        s.insert(max(t.x, t.y));
    }
    l[0] = ban();
    r[0] = ban();
    s.insert(0);

    vector<int> v;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        v.push_back(*it);

    for (int i = 0; i < v.size(); ++i)
    {
        dp[v[i]].first = dp[v[i]].second = INF;
    }
    dp[0].first = dp[0].second = 0;

    for (int i = 0; i < v.size() - 1; ++i)
    {
        int u = v[i];
        int t = v[i + 1];
        ubd(dp[u].first, l[u], t);
        ubd(dp[u].second, r[u], t);
    }

    cout << min(dp[v.back()].first, dp[v.back()].second) << endl;
    return 0;
}