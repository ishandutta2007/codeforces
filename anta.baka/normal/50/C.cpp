#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> point;

#define x first
#define y second

int n, ans;
vector<point> pt, up, down;

inline bool cw(point &a, point &b, point &c)
{
    return 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x) > 0;
}

inline bool ccw(point &a, point &b, point &c)
{
    return 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x) < 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pt.push_back({x, y});
        pt.push_back({x + 1, y});
        pt.push_back({x - 1, y});
        pt.push_back({x, y + 1});
        pt.push_back({x, y - 1});
    }
    sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    n  = pt.size();
    for(int i = 0; i < n; i++)
    {
        while(up.size() > 1 && cw(up[up.size() - 2], up.back(), pt[i])) up.pop_back();
        up.push_back(pt[i]);
        while(down.size() > 1 && ccw(down[down.size() - 2], down.back(), pt[i])) down.pop_back();
        down.push_back(pt[i]);
    }
    for(int i = 1; i < up.size(); i++) ans += max(abs(up[i].x - up[i - 1].x), abs(up[i].y - up[i - 1].y));
    for(int i = 1; i < down.size(); i++) ans += max(abs(down[i].x - down[i - 1].x), abs(down[i].y - down[i - 1].y));
    cout << ans;
}