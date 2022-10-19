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
const int N = 1000006;

int q;
int a[N], c[N];

const int m = 20;
int p[N][m];
bool z[N];

int go(int x)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (!z[p[x][i]])
            x = p[x][i];
    }
    return x;
}

void solv()
{
    cin >> q >> a[0] >> c[0];

    for (int i = 1; i <= q; ++i)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            cin >> p[i][0] >> a[i] >> c[i];
            for (int j = 1; j < m; ++j)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
        else
        {
            int x, w;
            cin >> x >> w;

            int ww = 0;
            ll g = 0;
            while (1)
            {
                if (w == 0)
                    break;
                if (z[x])
                    break;
                int u = go(x);
                if (a[u] > w)
                {
                    a[u] -= w;
                    ww += w;
                    g += w * 1LL * c[u];
                    w = 0;
                }
                else
                {
                    w -= a[u];
                    ww += a[u];
                    g += a[u] * 1LL * c[u];
                    a[u] = 0;
                    z[u] = true;
                }
            }

            cout << ww << ' ' << g << endl;
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