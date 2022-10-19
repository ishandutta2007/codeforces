#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005, INF = 1000000009;
struct ban
{
    int l, r, d;
};

int m, n, k, t;
int a[N];
ban b[N];
vector<pair<int, int> > v[N];

int dp[N];

bool stg(int x)
{
    stack<pair<int, int> > s;
    multiset<int> ss;
    s.push(m_p(0, 0));
    ss.insert(0);
    int maxu = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        maxu = max(maxu, (i - 1) * 2);
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j].second > x)
                maxu = max(maxu, v[i][j].first * 2);
        }
        int minu = INF;
        while (!s.empty() && s.top().first <= maxu)
        {
            ss.erase(ss.find(s.top().first + s.top().second));
            minu = min(minu, s.top().second);
            s.pop();
        }
        s.push(m_p(maxu, minu));
        ss.insert(maxu + minu);
        dp[i] = *(ss.begin()) + i;
        s.push(m_p(maxu, dp[i] - 3 * i));
        ss.insert(s.top().first + s.top().second);
    }
    return (dp[n + 1] <= t);
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].d);
    for (int i = 1; i <= k; ++i)
        v[b[i].l].push_back(m_p(b[i].r, b[i].d));
    int l = 1, r = m;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(a[m]))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%d\n", ans);
    return 0;
}