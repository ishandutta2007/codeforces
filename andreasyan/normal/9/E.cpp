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
const int N = 55;

int n, m;
vector<int> a[N], b[N];

int k;
int c[N];
bool dfs(int x, int p)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h] && b[x][i] != p)
            return false;
        if (!c[h])
        {
            if (!dfs(h, b[x][i]))
                return false;
        }
    }
    return true;
}

void tdfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            tdfs(h);
    }
}

int s[N], f[N];

int fi(int x)
{
    if (x == c[x])
        return x;
    return c[x] = fi(c[x]);
}

bool stg()
{
    if (m != n)
        return false;
    memset(c, false, sizeof c);
    tdfs(1);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            return false;
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
        b[x].push_back(i);
        b[y].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (sz(a[i]) > 2)
        {
            printf("NO\n");
            return;
        }
    }
    if (m > n)
    {
        printf("NO\n");
        return;
    }
    if (n == m)
    {
        if (stg())
        {
            printf("YES\n");
            printf("0\n");
            return;
        }
        printf("NO\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            k = i;
            if (!dfs(i, -1))
            {
                printf("NO\n");
                return;
            }
        }
    }
    multiset<int> u;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() == 1)
        {
            u.insert(i);
        }
        else if (a[i].size() == 0)
        {
            u.insert(i);
            u.insert(i);
        }
    }
    vector<pair<int, int> > ans;
    for (int ii = 0; ii < n - m - 1; ++ii)
    {
        int min1 = *u.begin();
        int min2 = N;
        for (auto it = u.begin(); it != u.end(); ++it)
        {
            if (fi(*it) != fi(min1))
            {
                min2 = min(min2, *it);
            }
        }
        ans.push_back(m_p(min1, min2));
        u.erase(u.find(min1));
        u.erase(u.find(min2));
        c[fi(min2)] = fi(min1);
        // -_-
    }
    ans.push_back(m_p(*u.begin(), *(++u.begin())));
    for (int i = 0; i < ans.size(); ++i)
    {
        ++m;
        a[ans[i].fi].push_back(ans[i].se);
        a[ans[i].se].push_back(ans[i].fi);
    }
    assert(stg());
    printf("YES\n");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}