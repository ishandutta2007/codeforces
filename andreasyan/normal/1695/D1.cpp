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

int n;
vector<int> g[N];

set<int> s;
void dfs(int x, int p, int p0)
{
    if (sz(g[x]) >= 3)
        p0 = x;
    else if (sz(g[x]) == 1)
        s.insert(p0);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x, p0);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    int r = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (sz(g[x]) >= 3)
        {
            r = x;
            break;
        }
    }

    if (r == 0)
    {
        cout << "1\n";
        return;
    }

    s.clear();
    dfs(r, r, r);
    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (sz(g[x]) == 1)
            ++ans;
    }
    ans -= sz(s);

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