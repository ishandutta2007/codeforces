#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000 + 7;
const ll inf = 1e18;

ll dp[N][2];
ll kek[N];
int x[N];
int p[N], c[N];

ll cost(int l, int r, int who)
{
    return kek[r] - (l ? kek[l - 1] : 0);
}

struct min_qu
{
    deque <ll> q;
    void push(ll x)
    {
        while (q.size() > 0 && q.back() > x)
        {
            q.pop_back();
        }
        q.push_back(x);
    }
    void clr()
    {
        q.clear();
    }
    void pop(ll x)
    {
        if (q.size() > 0 && q.front() == x)
        {
            q.pop_front();
        }
    }
    ll get()
    {
        return q.front();
    }
};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp[i][j] = 1e18;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    sort(x, x + n);
    vector <pair <int, int> > e;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    sort(e.begin(), e.end(), [] (pair <int, int> a, pair <int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first < b.first;
        }
    });
    for (int i = 0; i < m; i++)
    {
        p[i] = e[i].first, c[i] = e[i].second;
    }
    dp[0][0] = 0;
    min_qu q;
    for (int j = 1; j <= m; j++)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += abs(x[i] - p[j - 1]);
            kek[i] = sum;
        }
        q.clr();
        int it = j % 2;
        for (int i = 0; i <= min(n - 1, c[j - 1] - 1); i++)
        {
            q.push(dp[i][it ^ 1] - (i ? kek[i - 1] : 0));
            dp[i + 1][it] = min(dp[i + 1][it], q.get() + kek[i]);
        }
        for (int i = c[j - 1]; i < n; i++)
        {
            q.pop(dp[i - c[j - 1]][it ^ 1] - (i - c[j - 1] ? kek[i - c[j - 1] - 1] : 0));
            q.push(dp[i][it ^ 1] - (i ? kek[i - 1] : 0));
            dp[i + 1][it] = min(dp[i + 1][it], q.get() + kek[i]);
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][it] = min(dp[i][it], dp[i][it ^ 1]);
            dp[i][it ^ 1] = 1e18;
        }
    }
    if (dp[n][m % 2] == 1e18)
    {
        puts("-1");
        return 0;
    }
    printf("%lld\n", dp[n][m % 2]);
}