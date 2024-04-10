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

int n, k;
int a[N];
vector<int> g[N];

int z;

int e[N];
void dfs0(int x, int p)
{
    e[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        e[x] ^= e[h];
    }
}

bool ans;

bool c[N];
void dfs1(int x, int p)
{
    c[x] = false;
    int q = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        if (c[h])
        {
            c[x] = true;
            ++q;
        }
    }
    if (e[x] == z)
        c[x] = true;

    if (q >= 2)
        ans = true;
    if (e[x] == 0 && c[x])
        ans = true;
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    z = 0;
    for (int i = 1; i <= n; ++i)
        z ^= a[i];

    if (z == 0)
    {
        cout << "YES\n";
        return;
    }

    if (k == 2)
    {
        cout << "NO\n";
        return;
    }

    dfs0(1, 1);
    ans = false;
    dfs1(1, 1);

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}