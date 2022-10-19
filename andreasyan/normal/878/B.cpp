#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
#define int long long

int n, k, m;
int a[N];

int solv0()
{
    vector<pair<int, int> > v;
    for (int i = 1; i <= n * m; ++i)
    {
        int x = a[(i - 1) % n + 1];
        if (v.empty())
        {
            v.push_back(m_p(x, 1));
        }
        else
        {
            if (v.back().first == x)
            {
                v.back().second++;
            }
            else
            {
                v.push_back(m_p(x, 1));
            }
        }
        if (!v.empty() && v.back().second == k)
            v.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
        ans += v[i].second;
    return ans;
}

ll solv()
{
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        if (v.empty())
        {
            v.push_back(m_p(a[i], 1));
        }
        else
        {
            if (v.back().first == a[i])
            {
                v.back().second++;
            }
            else
            {
                v.push_back(m_p(a[i], 1));
            }
        }
        if (!v.empty() && v.back().second == k)
            v.pop_back();
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == v.size() - i - 1)
        {
            int q = 0;
            for (int j = i; j < v.size() - i; ++j)
            {
                q += v[j].second;
            }
            if ((q * 1LL * m) % k == 0)
                return 0;
            else
                return (q * 1LL * m) % k + i * k;
        }
        if (v[i].first != v[v.size() - i - 1].first)
        {
            int q = 0;
            for (int j = i; j < v.size() - i; ++j)
            {
                q += v[j].second;
            }
            return q * 1LL * m + i * k;
        }
        if (v[i].second + v[v.size() - i - 1].second != k)
        {
            int q = 0;
            for (int j = i; j < v.size() - i; ++j)
            {
                q += v[j].second;
            }
            if (v[i].second + v[v.size() - i - 1].second > k)
                return q * 1LL * m + i * k - (m - 1) * 1LL * k;
            else
                return q * 1LL * m + i * k;
        }
    }
    int q = 0;
    for (int i = 0; i < v.size(); ++i)
        q += v[i].second;
    if (m % 2 == 1)
        return q;
    else
        return 0;
}

int32_t main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("%lld\n", solv());
    return 0;
    while (1)
    {
        n = 20;
        m = rnf() % 20 + 1;
        k = rnf() % 20 + 1;
        for (int i = 1; i <= n; ++i)
        {
            a[i] = rnf() % 20 + 1;
        }
        if (solv() != solv0())
        {
            solv();
            printf("WA\n");
            return 0;
        }
    }
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}