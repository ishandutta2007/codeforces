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

bool dp[N][3];
void dfs(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }


    for (int z = 0; z < 3; ++z)
    {
        int q0, q1;
        q0 = q1 = sz(g[x]) / 2;
        if (sz(g[x]) % 2 == 1)
            ++q1;

        if (z == 0)
            --q0;
        else if (z == 1)
            --q1;

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (!dp[h][0] && !dp[h][1])
            {
                q0 = -1;
                break;
            }
            if (dp[h][0] && dp[h][1])
                continue;
            if (dp[h][0])
                --q0;
            else
                --q1;
        }

        if (q0 >= 0 && q1 >= 0)
            dp[x][z] = true;
        else
            dp[x][z] = false;
    }
}

void dfs1(int x, int p, int z)
{
    int q0, q1;
    q0 = q1 = sz(g[x]) / 2;
    if (sz(g[x]) % 2 == 1)
        ++q1;

    vector<int> v0, v1;
    if (z == 0)
    {
        --q0;
        v0.push_back(p);
    }
    else if (z == 1)
    {
        --q1;
        v1.push_back(p);
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (!dp[h][0] && !dp[h][1])
        {
            q0 = -1;
            break;
        }
        if (dp[h][0] && dp[h][1])
            continue;
        if (dp[h][0])
        {
            --q0;
            v0.push_back(h);
        }
        else
        {
            --q1;
            v1.push_back(h);
        }
    }
    assert(q0 >= 0 && q1 >= 0);

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (dp[h][0] && dp[h][1])
        {
            if (q0)
            {
                --q0;
                v0.push_back(h);
            }
            else
            {
                assert(q1);
                --q1;
                v1.push_back(h);
            }
        }
    }

    int u = (sz(g[x]) % 2);
    for (int i = 0; i < g[x].size(); ++i)
    {
        if (u == 0)
        {
            assert(!v0.empty());
            if (v0.back() == p)
            {
                cout << x << ' ' << p << "\n";
            }
            else
            {
                dfs1(v0.back(), x, u);
            }
            v0.pop_back();
        }
        else
        {
            assert(!v1.empty());
            if (v1.back() == p)
            {
                cout << x << ' ' << p << "\n";
            }
            else
            {
                dfs1(v1.back(), x, u);
            }
            v1.pop_back();
        }
        u ^= 1;
    }
}

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

    dfs(1, 1);

    if (dp[1][2])
    {
        cout << "YES\n";
        dfs1(1, 1, 2);
    }
    else
    {
        cout << "NO\n";
    }
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