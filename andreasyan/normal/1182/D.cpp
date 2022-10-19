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

int n;
vector<int> a[N];

int d[N];
void dfs(int x, int p)
{
    d[x] = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

vector<int> v;
void dfs1(int x, int p)
{
    v.push_back(x);
    int maxu = -1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        maxu = max(maxu, d[h]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (d[h] == maxu)
        {
            dfs1(h, x);
            return;
        }
    }
}

void dfs2(int x, int p)
{
    d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs2(h, x);
    }
}

bool stg(int r)
{
    dfs2(r, r);
    vector<pair<int, int> > v;
    for (int x = 1; x <= n; ++x)
    {
        v.push_back(m_p(d[x], a[x].size()));
    }
    sort(all(v));
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i].fi == v[i + 1].fi && v[i].se != v[i + 1].se)
        {
            return false;
        }
    }
    return true;
}

int dp[N];

void dfs4(int x, int p)
{
    dp[x] = x;
    int qh = 0;
    int hh = -1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs4(h, x);
        ++qh;
        hh = h;
    }
    if (qh > 1)
        dp[x] = 0;
    else if (qh == 1)
    {
        if (!dp[hh])
            dp[x] = 0;
        else
            dp[x] = dp[hh];
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    v.clear();
    dfs1(1, 1);
    int x = v.back();
    dfs(x, x);
    v.clear();
    dfs1(x, x);
    if (stg(v[v.size() / 2]))
    {
        printf("%d\n", v[v.size() / 2]);
        return;
    }
    if (stg(v[0]))
    {
        printf("%d\n", v[0]);
        return;
    }
    if (stg(v.back()))
    {
        printf("%d\n", v.back());
        return;
    }
    int r = v[v.size() / 2];
    dfs4(r, r);
    dfs(r, r);
    vector<pair<int, int> > vv;
    for (int i = 0; i < a[r].size(); ++i)
    {
        int h = a[r][i];
        if (!dp[h])
            continue;
        vv.push_back(m_p(d[h], dp[h]));
    }
    sort(all(vv));
    if (!vv.empty())
    {
        if (stg(vv[0].se))
        {
            printf("%d\n", vv[0].se);
            return;
        }
        if (stg(vv.back().se))
        {
            printf("%d\n", vv.back().se);
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}