#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 3003;
struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

long long ans;

bool onright(const ban& t1, const ban& t2, const ban& t3)
{
    return (t3.x - t1.x) * 1LL * (t2.y - t1.y) < (t2.x - t1.x) * 1LL * (t3.y - t1.y);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 1; i <= n; ++i)
    {
        ans += ((n - 1) * 1LL * (n - 2) * (n - 3) * 1LL * (n - 4)) / (1 * 2 * 3 * 4);
        vector<pair<long double, ban> > v;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            v.push_back(m_p(atan2(a[j].y - a[i].y, a[j].x - a[i].x), a[j]));
        }
        sort(v.begin(), v.end());
        long long yans = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            int l = 1, r = n - 2;
            int ans = 0;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (onright(a[i], v[j].second, v[(j + m) % (n - 1)].second))
                {
                    ans = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            yans += (ans * 1LL * (ans - 1) * 1LL * (ans - 2)) / (1 * 2 * 3);
            yans += ((n - 2 - ans) * 1LL * (n - 2 - ans - 1) * 1LL * (n - 2 - ans - 2)) / (1 * 2 * 3);
        }
        yans /= 2;
        ans -= yans;
    }
    printf("%lld\n", ans);
    return 0;
}