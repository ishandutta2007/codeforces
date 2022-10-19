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

int n, m;
int x[N], y[N], z[N];

int ans[N];
int a[N];
vector<int> g[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> x[i] >> y[i] >> z[i];

    for (int j = 0; j < 30; ++j)
    {
        for (int x = 1; x <= n; ++x)
        {
            g[x].clear();
            a[x] = -1;
        }
        for (int i = 1; i <= m; ++i)
        {
            if ((z[i] & (1 << j)))
            {
                if (x[i] == y[i])
                {
                    a[x[i]] = 1;
                }
                else
                {
                    g[x[i]].push_back(y[i]);
                    g[y[i]].push_back(x[i]);
                }
            }
            else
            {
                a[x[i]] = a[y[i]] = 0;
            }
        }

        for (int x = 1; x <= n; ++x)
        {
            if (a[x] != -1)
                continue;
            bool z = false;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (a[h] == 0)
                {
                    z = true;
                    break;
                }
            }
            if (z)
            {
                a[x] = 1;
            }
            else
            {
                a[x] = 0;
            }
        }

        for (int x = 1; x <= n; ++x)
        {
            ans[x] |= (a[x] * (1 << j));
        }
    }

    for (int x = 1; x <= n; ++x)
        cout << ans[x] << ' ';
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