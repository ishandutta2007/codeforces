#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int K = 17, N = 5003;

int k;
int n[K];
long long a[K][N];
long long sum[K];

map<long long, int> mp;

map<long long, long long> h;

long long s, f;
map<long long, int> c;
map<long long, long long> p;

bool dfs(long long x)
{
    c[x] = 1;
    if (mp.find(h[x]) == mp.end())
    {
        c[x] = 2;
        return false;
    }
    if (x == h[x])
    {
        s = x;
        f = x;
        c[x] = 2;
        return true;
    }
    if (mp[x] == mp[h[x]])
    {
        c[x] = 2;
        return false;
    }
    if (c[h[x]] == 1)
    {
        s = h[x];
        f = x;
        c[x] = 2;
        return true;
    }
    if (c[h[x]] == 2)
    {
        c[x] = 2;
        return false;
    }
    p[h[x]] = x;
    if (dfs(h[x]))
    {
        c[x] = 2;
        return true;
    }
    c[x] = 2;
    return false;
}

vector<long long> b[1 << K];

bool dp[1 << K];

pair<long long, int> yans[K];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; ++j)
            scanf("%lld", &a[i][j]);
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            mp[a[i][j]] = i;
            ans += a[i][j];
            sum[i] += a[i][j];
        }
    }
    if (ans % k != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    ans /= k;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            h[a[i][j]] = ans - sum[i] + a[i][j];
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            if (c[a[i][j]] == 0)
            {
                if (dfs(a[i][j]))
                {
                    vector<long long> v;
                    for (long long u = f; u != s; u = p[u])
                        v.push_back(u);
                    v.push_back(s);
                    reverse(v.begin(), v.end());
                    int x = 0;
                    bool z = true;
                    for (int i = 0; i < v.size(); ++i)
                    {
                        if ((x & (1 << mp[v[i]])))
                        {
                            z = false;
                            break;
                        }
                        x = (x | (1 << mp[v[i]]));
                    }
                    if (z)
                        b[x] = v;
                }
            }
        }
    }
    dp[0] = true;
    for (int x = 1; x < (1 << k); ++x)
    {
        for (int y = x; y; y = ((y - 1) & x))
        {
            int z = (x ^ y);
            if (dp[z] && !b[y].empty())
            {
                dp[x] = true;
                break;
            }
        }
    }
    if (!dp[(1 << k) - 1])
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int x = (1 << k) - 1;
    while (1)
    {
        if (x == 0)
            break;
        for (int y = x; y; y = ((y - 1) & x))
        {
            int z = (x ^ y);
            if (dp[z] && !b[y].empty())
            {
                for (int i = 0; i < b[y].size(); ++i)
                {
                    yans[mp[h[b[y][i]]]] = m_p(h[b[y][i]], mp[b[y][i]]);
                }
                x = z;
                break;
            }
        }
    }
    for (int i = 0; i < k; ++i)
        cout << yans[i].first << ' ' << yans[i].second + 1 << endl;
    return 0;
}