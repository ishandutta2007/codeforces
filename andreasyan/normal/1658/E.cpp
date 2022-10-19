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
const int N = 2003;

int n, k;
int a[N][N];

pair<int, int> u[N * N];

char ans[N][N];

int t[N * 2][N * 2];

void ubdy(int x, int y)
{
    while (y <= n * 2)
    {
        ++t[x][y];
        y += (y & (-y));
    }
}

void ubdx(int x, int y)
{
    y += n;
    while (x <= n * 2)
    {
        ubdy(x, y);
        x += (x & (-x));
    }
}

int qryy(int x, int y)
{
    int ans = 0;
    while (y)
    {
        ans += t[x][y];
        y -= (y & (-y));
    }
    return ans;
}

int qryx(int x, int y)
{
    y += n;
    x = max(x, 0);
    x = min(x, n * 2);
    y = max(y, 0);
    y = min(y, n * 2);

    int ans = 0;
    while (x)
    {
        ans += qryy(x, y);
        x -= (x & (-x));
    }
    return ans;
}

int qry(int x1, int y1_, int x2, int y2)
{
    if (y1_ > y2)
        swap(y1_, y2);
    return qryx(x2, y2) - qryx(x2, y1_ - 1) - qryx(x1 - 1, y2) + qryx(x1 - 1, y1_ - 1);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            u[a[i][j]] = m_p(i, j);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ans[i][j] = 'G';
        }
        ans[i][n] = 0;
    }

    int q = 0;
    for (int i = n * n; i >= 1; --i)
    {
        int x = u[i].fi;
        int y = u[i].se;

        int u = qry((x - k + y), (x - k - y), (x + k + y), (x + k - y));
        if (u != q)
            continue;
        ans[x - 1][y - 1] = 'M';
        ++q;
        ubdx(x + y, x - y);
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
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