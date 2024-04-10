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

int n, m;
vector<int> g[N];
int z[N];

int k;
int c[N];
void dfs0(int x)
{
    c[x] = k;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs0(h);
    }
}

bool cc[N];

vector<int> ans;
void dfs(int x, int p)
{
    c[x] = 1;
    ans.push_back(x);
    z[x] ^= 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        dfs(h, x);
    }
    if (x != p)
    {
        if (z[x])
        {
            ans.push_back(p);
            z[p] ^= 1;
            ans.push_back(x);
            z[x] ^= 1;
            ans.push_back(p);
            z[p] ^= 1;
        }
        else
        {
            ans.push_back(p);
            z[p] ^= 1;
        }
    }
    else
    {
        if (z[x])
        {
            ans.push_back(g[x][0]);
            z[g[x][0]] ^= 1;
            ans.push_back(x);
            z[x] ^= 1;
            ans.push_back(g[x][0]);
            z[g[x][0]] ^= 1;
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &z[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs0(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (z[i])
            cc[c[i]] = true;
    }
    int qq = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (cc[i])
            ++qq;
    }
    if (qq == 0)
    {
        printf("0\n");
        return;
    }
    if (qq > 1)
    {
        printf("-1\n");
        return;
    }
    int r;
    for (int i = 1; i <= n; ++i)
    {
        if (z[i])
            r = i;
    }
    memset(c, 0, sizeof c);
    dfs(r, r);
    assert(ans.size() <= n * 4);
    for (int i = 1; i <= n; ++i)
        assert(!z[i]);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
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