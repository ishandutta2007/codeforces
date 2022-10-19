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
const int N = 3003;

int n, m;
char a[N][N];

int l[N][N], r[N][N];

int t[N];
void ubd(int x, int y)
{
    while (x < N)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

vector<int> v[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '.')
            {
                l[i][j] = j + 1;
                continue;
            }
            if (a[i][j - 1] == 'z')
                l[i][j] = l[i][j - 1];
            else
                l[i][j] = j;
        }
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == '.')
            {
                r[i][j] = j - 1;
                continue;
            }
            if (a[i][j + 1] == 'z')
                r[i][j] = r[i][j + 1];
            else
                r[i][j] = j;
        }
    }
    ll ans = 0;
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
            v[i].clear();
        int q = 0;
        for (int x = 1, y = j; x <= n && y >= 1; ++x, --y)
        {
            if (a[x][y] == 'z')
            {
                ++q;
                v[x].push_back(y);
                v[x - min(r[x][y] - y + 1, q)].push_back(-y);
            }
            else
            {
                q = 0;
            }
        }
        memset(t, 0, sizeof t);
        for (int x = 1, y = j; x <= n && y >= 1; ++x, --y)
        {
            if (a[x][y] == 'z')
            {
                ubd(l[x][y], 1);
            }
            for (int i = 0; i < v[x].size(); ++i)
            {
                if (v[x][i] > 0)
                    ans += qry(v[x][i]);
                else
                    ans -= qry(-v[x][i]);
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int i = 1; i <= n; ++i)
            v[i].clear();
        int q = 0;
        for (int x = i, y = m; x <= n && y >= 1; ++x, --y)
        {
            if (a[x][y] == 'z')
            {
                ++q;
                v[x].push_back(y);
                v[x - min(r[x][y] - y + 1, q)].push_back(-y);
            }
            else
            {
                q = 0;
            }
        }
        memset(t, 0, sizeof t);
        for (int x = i, y = m; x <= n && y >= 1; ++x, --y)
        {
            if (a[x][y] == 'z')
            {
                ubd(l[x][y], 1);
            }
            for (int i = 0; i < v[x].size(); ++i)
            {
                if (v[x][i] > 0)
                    ans += qry(v[x][i]);
                else
                    ans -= qry(-v[x][i]);
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}