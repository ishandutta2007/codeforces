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
const int N = 300005;

int n;
int c[N];
vector<int> g[N];

int qq;
int q[N];

bool c1[N], c0[N];

void dfs(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }
    q[x] += c[x];

    if (c[x] == 1)
        c1[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            c1[x] = true;
    }

    c0[x] = true;

    if (c1[x])
        c0[x] = false;

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] >= 2)
            c0[x] = false;
    }

    if (qq - q[x] >= 2)
        c0[x] = false;
}

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        qq += c[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    queue<int> q;
    for (int x = 1; x <= n; ++x)
    {
        ans[x] = 1;
        if (c0[x])
            q.push(x);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        ans[x] = 0;

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (ans[h] && c1[h] == false)
                q.push(h);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}