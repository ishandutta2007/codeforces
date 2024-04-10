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

int n, k;
vector<int> g[N];

int d[N];
void dfs(int x, int u, int& ans)
{
    d[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h, u, ans);
        if (d[h] + 1 == u && x != 1)
        {
            ++ans;
            d[h] = -1;
        }
        d[x] = max(d[x], d[h] + 1);
    }
}

bool stg(int u)
{
    int ans = 0;
    dfs(1, u, ans);
    return (ans <= k);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    int l = 1, r = n - 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << "\n";
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