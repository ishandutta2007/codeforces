#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;
const long long INF = 1000000009000000009;

int n, k;
int a[N];
vector<pair<int, int> > v;

int p[N], s[N];
long long qp[N], qs[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int q = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            v.push_back(m_p(a[i - 1], q));
            q = 1;
        }
        else
            ++q;
    }
    v.push_back(m_p(a[n], q));
    p[0] = v[0].second;
    for (int i = 1; i < v.size(); ++i)
    {
        p[i] = p[i - 1] + v[i].second;
        qp[i] = qp[i - 1] + p[i - 1] * 1LL * (v[i].first - v[i - 1].first);
    }
    s[v.size() - 1] = v.back().second;
    for (int i = (int)v.size() - 2; i >= 0; --i)
    {
        s[i] = s[i + 1] + v[i].second;
        qs[i] = qs[i + 1] + s[i + 1] * 1LL * (v[i + 1].first - v[i].first);
    }
    long long ans = INF;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].second >= k)
        {
            ans = 0;
            break;
        }
        if (p[i] >= k)
        {
            long long yans = 0;
            yans += qp[i - 1];
            yans += (p[i - 1] * 1LL * (v[i].first - 1 - v[i - 1].first));
            yans += (k - v[i].second);
            ans = min(ans, yans);
        }
        if (s[i] >= k)
        {
            long long yans = 0;
            yans += qs[i + 1];
            yans += (s[i + 1] * 1LL * (v[i + 1].first - v[i].first - 1));
            yans += (k - v[i].second);
            ans = min(ans, yans);
        }
        long long yans = 0;
        if (i > 0)
        {
            yans += qp[i - 1];
            yans += (p[i - 1] * 1LL * (v[i].first - 1 - v[i - 1].first));
        }
        if (i < v.size() - 1)
        {
            yans += qs[i + 1];
            yans += (s[i + 1] * 1LL * (v[i + 1].first - v[i].first - 1));
        }
        yans += (k - v[i].second);
        ans = min(ans, yans);
    }
    printf("%lld\n", ans);
    return 0;
}