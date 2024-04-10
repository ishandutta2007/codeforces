#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005, s = 502;

int n;
int a[N];

int m;
vector<pair<int, int> > v[N];

long long ans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(m_p(b, i));
    }
    deque<vector<long long> > q;
    for (int i = n; i >= 1; --i)
    {
        vector<long long> vv;
        vv.assign(s, 0);
        for (int j = 1; j <= s; ++j)
        {
            if (i + j > n)
                vv[j - 1] = a[i];
            else
                vv[j - 1] = q[j - 1][j - 1] + a[i];
        }
        q.push_front(vv);
        if (q.size() > s)
            q.pop_back();
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j].first <= s)
            {
                ans[v[i][j].second] = q[0][v[i][j].first - 1];
            }
            else
            {
                long long yans = 0;
                for (int k = i; k <= n; k += v[i][j].first)
                    yans += a[k];
                ans[v[i][j].second] = yans;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}