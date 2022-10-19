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

int p[N];
void dfs0(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p[x])
            continue;
        p[h] = x;
        dfs0(h);
    }
}

int q[N], qt[N];

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int x = 2; x <= n; ++x)
        g[p[x]].push_back(x);

    for (int x = 1; x <= n; ++x)
        qt[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        q[x] = sz(g[x]);
    }

    queue<int> qp;
    for (int x = 1; x <= n; ++x)
    {
        if (q[x] == 0)
            qp.push(x);
    }

    vector<int> v;
    while (!qp.empty())
    {
        int x = qp.front();
        qp.pop();
        if (x == 1)
            break;
        if (q[x] == 0)
        {
            ++qt[p[x]];
        }
        else
        {
            v.push_back(qt[x]);
            --q[p[x]];
        }
        if (q[p[x]] == qt[p[x]])
            qp.push(p[x]);
    }

    int ans = qt[1];
    if (ans == 0)
        ++ans;
    for (int i = 0; i < sz(v); ++i)
        ans += (v[i] - 1);

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
        solv();
    return 0;
}