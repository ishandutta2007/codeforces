#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 5, M = 102;

int n, m;
int a[N][M];

int k;
int u[22];

int ans;
void rec(int j)
{
    if (j == k + 1)
    {
        int yans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int pans = 0;
            for (int j = 1; j <= k; ++j)
            {
                pans = max(pans, a[i][u[j]]);
            }
            yans += pans;
        }
        ans = max(ans, yans);
        return;
    }
    int t[N];
    for (int i = 1; i <= n; ++i)
    {
        t[i] = a[i][u[j]];
    }
    for (int si = 1; si <= n; ++si)
    {
        int ii = 0;
        for (int i = si; i <= n; ++i)
        {
            a[++ii][u[j]] = t[i];
        }
        for (int i = 1; i < si; ++i)
        {
            a[++ii][u[j]] = t[i];
        }
        rec(j + 1);
    }
}

void solv()
{
    vector<pair<int, int> > v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            v.push_back(m_p(a[i][j], j));
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    set<int> s;
    for (int i = 0; i < min(10, (int)v.size()); ++i)
    {
        s.insert(v[i].second);
    }
    k = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        u[++k] = *it;
    }
    ans = 0;
    rec(1);
    cout << ans << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}