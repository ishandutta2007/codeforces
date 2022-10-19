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
const int N = 500005, m = 20;

int f(int x)
{
    if (x == 0)
        return m;
    int ans = 0;
    while (x % 2 == 0)
    {
        ++ans;
        x /= 2;
    }
    return ans;
}

int n;
int a[N], b[N];

int u[N];
int solv0()
{
    for (int i = 0; i < n; ++i)
        u[i] = i;
    int ans = 0;
    do
    {
        for (int x = 0; x < (1 << n); ++x)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    swap(a[u[i]], b[u[i]]);
            }
            int yans = 20;
            for (int i = 0; i < n; ++i)
                yans = min(yans, f(b[u[i]] ^ a[u[(i + 1) % n]]));
            ans = max(ans, yans);
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    swap(a[u[i]], b[u[i]]);
            }
        }
    } while (next_permutation(u, u + n));
    return ans;
}

bool c[(1 << m)];

vector<int> g[(1 << m)];

void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
}

bool stg(int s)
{
    for (int i = 0; i < (1 << m); ++i)
    {
        c[i] = false;
        g[i].clear();
    }
    for (int i = 0; i < n; ++i)
    {
        int x = a[i];
        int y = b[i];
        for (int j = s; j < m; ++j)
        {
            if ((x & (1 << j)))
                x ^= (1 << j);
            if ((y & (1 << j)))
                y ^= (1 << j);
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < (1 << m); ++i)
    {
        if (g[i].size() % 2 == 1)
            return false;
    }
    for (int i = 0; i < (1 << m); ++i)
    {
        if (!g[i].empty())
        {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int x = a[i];
        int y = b[i];
        for (int j = s; j < m; ++j)
        {
            if ((x & (1 << j)))
                x ^= (1 << j);
            if ((y & (1 << j)))
                y ^= (1 << j);
        }
        if (!c[x])
            return false;
        if (!c[y])
            return false;
    }
    return true;
}

int solv1()
{
    for (int s = m; s >= 0; --s)
    {
        if (stg(s))
            return s;
    }
}

vector<int> gi[(1 << m)];

vector<int> ans;
void dfs1(int x)
{
    while (1)
    {
        if (g[x].empty())
            break;
        int h = g[x].back();
        int hi = gi[x].back();
        g[x].pop_back();
        gi[x].pop_back();
        if (!c[(hi - 1) / 2])
        {
            c[(hi - 1) / 2] = true;
            dfs1(h);
        }
    }
    ans.push_back(x);
}

map<pair<int, int>, vector<int> > mp;

void solv()
{
    int l = 0, r = m;
    int s;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (stg(mid))
        {
            s = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", s);
    for (int i = 0; i < (1 << m); ++i)
    {
        c[i] = false;
        g[i].clear();
    }
    for (int i = 0; i < n; ++i)
    {
        int x = a[i];
        int y = b[i];
        for (int j = s; j < m; ++j)
        {
            if ((x & (1 << j)))
                x ^= (1 << j);
            if ((y & (1 << j)))
                y ^= (1 << j);
        }
        a[i] = x;
        b[i] = y;
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back((i + 1) * 2 - 1);
        gi[y].push_back((i + 1) * 2);
        mp[m_p(min(x, y), max(x, y))].push_back(i);
    }
    for (int i = 0; i < (1 << m); ++i)
    {
        if (!g[i].empty())
        {
            dfs1(i);
            break;
        }
    }
    for (int i = 0; i < sz(ans) - 1; ++i)
    {
        int x = ans[i];
        int y = ans[(i + 1) % sz(ans)];
        int u = mp[m_p(min(x, y), max(x, y))].back();
        mp[m_p(min(x, y), max(x, y))].pop_back();
        if ((x == a[u] && y == b[u]))
            printf("%d %d ", (u + 1) * 2 - 1, (u + 1) * 2);
        else
            printf("%d %d ", (u + 1) * 2, (u + 1) * 2 - 1);
    }
    /*for (int i = 0; i < n; ++i)
    {
        if (ans[i] % 2 == 1)
        {
            printf("%d %d ", ans[i], ans[i] + 1);
        }
        else
        {
            printf("%d %d ", ans[i], ans[i] - 1);
        }
    }
    printf("\n");*/
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    /*while (1)
    {
        n = 5;
        for (int i = 0; i < n; ++i)
        {
            a[i] = rnf() % (1 << m);
            b[i] = rnf() % (1 << m);
        }
        if (solv1() != solv0())
        {
            printf("WA\n");
            solv0();
            solv1();
        }
        else
            printf("OK\n");
    }*/
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}