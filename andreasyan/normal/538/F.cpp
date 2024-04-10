#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
int a[N];

vector<pair<int, pair<int, int> > > v[N];

int ans[N];

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int z = 0;
    map<int, int> mp;
    vector<int> vv;
    for (int i = 1; i <= n; ++i)
        vv.push_back(a[i]);
    sort(vv.begin(), vv.end());
    for (int i = 0; i < n; ++i)
    {
        if (!i || vv[i] != vv[i - 1])
        {
            mp[vv[i]] = ++z;
        }
    }
    for (int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; ; ++k)
        {
            int l = k * (i - 1) + 2;
            int r = min(n, k * i + 1);
            if (l > n)
                break;
            v[l - 1].push_back(m_p(-1, m_p(a[i], k)));
            v[r].push_back(m_p(1, m_p(a[i], k)));
            if (i == 1 && r == n)
                break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ubd(a[i]);
        for (int j = 0; j < v[i].size(); ++j)
        {
            ans[v[i][j].second.second] += v[i][j].first * qry(1, v[i][j].second.first - 1);
        }
    }
    for (int i = 1; i <= n - 1; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}