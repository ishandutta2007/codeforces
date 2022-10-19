#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

long long x0, y0, ax, ay, bx, by;
long long xs, ys, t;

vector<pair<long long, long long> > v;

long long dist(pair<long long, long long> a, pair<long long, long long> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    scanf("%lld%lld%lld", &xs, &ys, &t);
    v.push_back(m_p(x0, y0));
    while (1)
    {
        long long yx = v.back().first * ax + bx;
        long long yy = v.back().second * ay + by;
        if (dist(m_p(xs, ys), m_p(yx, yy)) > t && dist(m_p(xs, ys), m_p(yx, yy)) > dist(m_p(xs, ys), v.back()))
            break;
        v.push_back(m_p(yx, yy));
    }
    int ans = 0;
    for (int l = 0; l < v.size(); ++l)
    {
        for (int r = l; r < v.size(); ++r)
        {
            long long tt = t;
            tt -= dist(m_p(xs, ys), v[l]);
            for (int i = l + 1; i <= r; ++i)
            {
                tt -= dist(v[i - 1], v[i]);
            }
            if (tt >= 0)
                ans = max(ans, (r - l + 1));
            tt = t;
            tt -= dist(m_p(xs, ys), v[r]);
            for (int i = r - 1; i >= l; --i)
            {
                tt -= dist(v[i + 1], v[i]);
            }
            if (tt >= 0)
                ans = max(ans, (r - l + 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}