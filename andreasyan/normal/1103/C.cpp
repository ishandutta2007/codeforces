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
const int N = 500005;

int n, m, k;
vector<int> g[N];

bool c[N];
int d[N];
int p[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        d[h] = d[x] + 1;
        p[h] = x;
        dfs(h);
    }
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    d[1] = 1;
    dfs(1);

    for (int x = 1; x <= n; ++x)
    {
        if (d[x] * 1LL * k >= n)
        {
            cout << "PATH\n";
            cout << d[x] << "\n";
            while (x)
            {
                cout << x << ' ';
                x = p[x];
            }
            cout << "\n";
            return;
        }
    }

    memset(c, false, sizeof c);
    for (int x = 2; x <= n; ++x)
        c[p[x]] = true;

    cout << "CYCLES\n";
    int q = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        ++q;
        if (q > k)
            break;

        bool z = false;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p[x])
                continue;
            if ((d[x] - d[h] + 1) % 3 != 0)
            {
                cout << d[x] - d[h] + 1 << "\n";
                int y = x;
                while (1)
                {
                    cout << y << ' ';
                    if (y == h)
                        break;
                    y = p[y];
                }
                cout << "\n";
                z = true;
                break;
            }
        }

        if (!z)
        {
            int h1 = 0, h2 = 0;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (h == p[x])
                    continue;
                if (h1)
                    h2 = h;
                else
                    h1 = h;
            }
            if (d[h2] > d[h1])
                swap(h1, h2);

            cout << d[h1] - d[h2] + 2 << "\n";
            cout << x << ' ';
            int y = h1;
            while (1)
            {
                cout << y << ' ';
                if (y == h2)
                    break;
                y = p[y];
            }
            cout << "\n";
        }
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}