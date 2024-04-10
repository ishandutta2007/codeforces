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
const int N = 1003;
const int INF = 2000000009;

int n;
int x[N], y[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int p0[N], p1[N], p2[N];
vector<int> v[N];

int q[N * 4];
bool c[N * 4];
bool stg(ll d)
{
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i)
        v[i].clear();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (x[i] == x[j] || y[i] == y[j])
            {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= d)
                    kpc(i, j);
            }
        }
    }

    vector<ll> yy;
    for (int i = 1; i <= n; ++i)
    {
        yy.push_back(y[i] - d);
        yy.push_back(y[i]);
        yy.push_back(y[i] + d);
    }
    sort(all(yy));
    for (int i = 1; i <= n; ++i)
    {
        p0[i] = lower_bound(all(yy), y[i] - d) - yy.begin() + 1;
        p1[i] = lower_bound(all(yy), y[i]) - yy.begin() + 1;
        p2[i] = lower_bound(all(yy), y[i] + d) - yy.begin() + 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i] = fi(p[i]);
        v[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        int qq = 0;
        memset(q, 0, sizeof q);
        for (int j = 1; j <= n; ++j)
        {
            if (j == p[i] || v[j].empty())
                continue;
            ++qq;

            int l = -1, r = sz(yy) + 5;
            for (int k = 0; k < v[j].size(); ++k)
            {
                int u = v[j][k];
                if (x[u] == x[i])
                {
                    if (y[u] > y[i])
                    {
                        if (y[u] - d <= y[i] + d)
                        {
                            //vv.push_back(m_p(y[u] - d, 1));
                            //vv.push_back(m_p(y[i] + d + 1, -1));
                            r = min(r, p0[u]);
                        }
                    }
                    else
                    {
                        if (y[u] + d >= y[i] - d)
                        {
                            //vv.push_back(m_p(y[i] - d, 1));
                            //vv.push_back(m_p(y[u] + d + 1, -1));
                            l = max(l, p2[u]);
                        }
                    }
                }
            }
            for (int k = 0; k < v[j].size(); ++k)
            {
                int u = v[j][k];
                if (x[u] != x[i])
                {
                    if (abs(x[u] - x[i]) <= d && abs(y[u] - y[i]) <= d)
                    {
                        //vv.push_back(m_p(y[u], 1));
                        //vv.push_back(m_p(y[u] + 1, -1));
                        if (l < p1[u] && p1[u] < r)
                        {
                            if (c[p1[u]])
                                continue;
                            c[p1[u]] = true;
                            q[p1[u]]++;
                            q[p1[u] + 1]--;
                        }
                    }
                }
            }
            for (int k = 0; k < v[j].size(); ++k)
            {
                int u = v[j][k];
                if (x[u] != x[i])
                {
                    if (abs(x[u] - x[i]) <= d && abs(y[u] - y[i]) <= d)
                    {
                        //vv.push_back(m_p(y[u], 1));
                        //vv.push_back(m_p(y[u] + 1, -1));
                        if (l < p1[u] && p1[u] < r)
                        {
                            c[p1[u]] = false;
                        }
                    }
                }
            }
            if (l >= 1)
            {
                q[1]++;
                q[l + 1]--;
            }
            if (r <= sz(yy))
            {
                q[r]++;
                q[sz(yy) + 1]--;
            }
        }
        for (int k = 1; k <= sz(yy) + 1; ++k)
        {
            q[k] += q[k - 1];
            if (q[k] == qq)
                return true;
        }
    }
    return false;
}

bool stgg(ll d)
{
    if (stg(d))
        return true;
    for (int i = 1; i <= n; ++i)
        swap(x[i], y[i]);
    return stg(d);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    int l = 0, r = INF;
    int ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (stgg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}