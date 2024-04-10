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
const int N = 2003, INF = 1000000009;

int n;
int a[N][N];

bool c[N];
ll d[N];

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            cin >> a[x][y];
            a[y][x] = a[x][y];
        }
    }

    int minu = INF;
    int minx, miny;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            if (a[x][y] < minu)
            {
                minu = a[x][y];
                minx = x;
                miny = y;
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        d[x] = INF * 1LL * INF;
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (x == y)
                continue;
            d[x] = min(d[x], (a[x][y] - minu) * 2LL);
        }
    }
    d[minx] = 0;
    d[miny] = 0;
    for (int ii = 0; ii < n; ++ii)
    {
        int x = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            if (x == 0 || d[x] > d[i])
                x = i;
        }
        c[x] = true;

        for (int h = 1; h <= n; ++h)
        {
            if (x == h)
                continue;
            d[h] = min(d[h], d[x] + a[x][h] - minu);
        }
    }

    for (int x = 1; x <= n; ++x)
        cout << d[x] + (n - 1) * 1LL * minu << "\n";
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