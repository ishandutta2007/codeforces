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

int n;
vector<int> a[N];
map<int, map<int, int> > b;

int t[N];
void dfs0(int x, int p)
{
    t[x] = x;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        t[x] = t[h];
    }
}

vector<pair<pair<int, int>, int> > ans;

vector<int> v;
bool dfs1(int x, int p, int y)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (dfs1(h, x, y))
            return true;
    }
    v.pop_back();
    return false;
}

void gor(int x, int y, int z)
{
    ans.push_back(m_p(m_p(x, y), z));
    v.clear();
    dfs1(x, x, y);
    for (int i = 0; i < sz(v) - 1; ++i)
    {
        b[v[i]][v[i + 1]] -= z;
        b[v[i + 1]][v[i]] -= z;
    }
}

void dfs(int x, int p)
{
    dfs0(x, x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        int t1 = -1, t2 = -1;
        for (int j = 0; j < a[x].size(); ++j)
        {
            int h1 = a[x][j];
            if (h1 == h)
                continue;
            if (t1 == -1)
                t1 = t[h1];
            else
                t2 = t[h1];
        }
        int u = b[x][h];
        gor(t[h], t1, u / 2);
        gor(t[h], t2, u / 2);
        gor(t1, t2, -u / 2);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(y);
        a[y].push_back(x);
        b[x][y] = z;
        b[y][x] = z;
    }
    for (int x = 1; x <= n; ++x)
    {
        if (sz(a[x]) == 2)
        {
            printf("NO\n");
            return;
        }
    }
    if (n == 2)
    {
        printf("YES\n");
        printf("1\n");
        printf("1 2 %d\n", b[1][2]);
        return;
    }
    int r;
    for (int x = 1; x <= n; ++x)
    {
        if (sz(a[x]) > 1)
        {
            r = x;
            break;
        }
    }
    dfs(r, r);
    printf("YES\n");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
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