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
const int N = 200005;

ll ans;

int n;
vector<int> g[N];

bool c[N];
int pp[N];
int s, f;
bool dfs0(int x, int p)
{
    c[x] = true;
    pp[x] = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (!c[h])
        {
            if (dfs0(h, x))
                return true;
        }
        else
        {
            s = h;
            f = x;
            return true;
        }
    }
    return false;
}

vector<int> v;

int q[N];
void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs(h, x);
        ans += (q[x] * 1LL * q[h]);
        q[x] += q[h];
    }
}

void solv()
{
    scanf("%d", &n);

    ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        c[x] = false;
    }
    v.clear();

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    assert(dfs0(1, 1));
    for (int x = f; x != s; x = pp[x])
        v.push_back(x);
    v.push_back(s);

    for (int x = 1; x <= n; ++x)
        c[x] = false;
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        c[x] = true;
    }

    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        dfs(x, x);
    }

    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        ans += (q[x] * 1LL * (n - q[x]));
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}