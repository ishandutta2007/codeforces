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
const int N = 102;

int n, m;
char a[N][N];

vector<vector<pair<int, int> > > ans;
void ave(int x, int y, int x1, int y1_)
{
    vector<pair<int, int> > v;
    for (int i = x; i <= x + 1; ++i)
    {
        for (int j = y; j <= y + 1; ++j)
        {
            if (!(i == x1 && j == y1_))
            {
                if (a[i][j] == '0')
                    a[i][j] = '1';
                else
                    a[i][j] = '0';
                v.push_back(m_p(i, j));
            }
        }
    }
    ans.push_back(v);
}

bool stg(int x, int y, vector<pair<int, int> > v)
{
    for (int i = x; i <= x + 1; ++i)
    {
        for (int j = y; j <= y + 1; ++j)
        {
            int u = a[i][j] - '0';
            for (int k = 0; k < sz(v); ++k)
            {
                if (m_p(i, j) != v[k])
                    u ^= 1;
            }
            if (u == 1)
                return false;
        }
    }
    return true;
}

void dz(int x, int y)
{
    if (stg(x, y, {}))
        return;

    for (int x1 = x; x1 <= x + 1; ++x1)
    {
        for (int y1_ = y; y1_ <= y + 1; ++y1_)
        {
            if (stg(x, y, {m_p(x1, y1_)}))
            {
                ave(x, y, x1, y1_);
                return;
            }
        }
    }

    for (int x1 = x; x1 <= x + 1; ++x1)
    {
        for (int y1_ = y; y1_ <= y + 1; ++y1_)
        {
            for (int x2 = x; x2 <= x + 1; ++x2)
            {
                for (int y2 = y; y2 <= y + 1; ++y2)
                {
                    if (stg(x, y, {m_p(x1, y1_), m_p(x2, y2)}))
                    {
                        ave(x, y, x1, y1_);
                        ave(x, y, x2, y2);
                        return;
                    }
                }
            }
        }
    }

    for (int x1 = x; x1 <= x + 1; ++x1)
    {
        for (int y1_ = y; y1_ <= y + 1; ++y1_)
        {
            for (int x2 = x; x2 <= x + 1; ++x2)
            {
                for (int y2 = y; y2 <= y + 1; ++y2)
                {
                    for (int x3 = x; x3 <= x + 1; ++x3)
                    {
                        for (int y3 = y; y3 <= y + 1; ++y3)
                        {
                            if (stg(x, y, {m_p(x1, y1_), m_p(x2, y2), m_p(x3, y3)}))
                            {
                                ave(x, y, x1, y1_);
                                ave(x, y, x2, y2);
                                ave(x, y, x3, y3);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    ave(x, y, x, y);
    ave(x, y, x + 1, y);
    ave(x, y, x, y + 1);
    ave(x, y, x + 1, y + 1);
}

void solv()
{
    ans.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }

    if (n % 2 == 1 && m % 2 == 1)
    {
        if (a[n][m] == '1')
        {
            ave(n - 1, m - 1, n - 1, m);
        }
    }
    if (n % 2 == 1)
    {
        for (int j = 1; j <= (m / 2) * 2; ++j)
        {
            if (a[n][j] == '1')
            {
                if (j < (m / 2) * 2)
                {
                    ave(n - 1, j, n, j + 1);
                }
                else
                {
                    ave(n - 1, j - 1, n, j - 1);
                }
            }
        }
    }
    if (m % 2 == 1)
    {
        for (int i = 1; i <= (n / 2) * 2; ++i)
        {
            if (a[i][m] == '1')
            {
                if (i < (n / 2) * 2)
                {
                    ave(i, m - 1, i + 1, m);
                }
                else
                {
                    ave(i - 1, m - 1, i - 1, m);
                }
            }
        }
    }

    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j += 2)
        {
            if (i + 1 <= n && j + 1 <= m)
                dz(i, j);
        }
    }

    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
    {
        for (int j = 0; j < 3; ++j)
            printf("%d %d ", ans[i][j].fi, ans[i][j].se);
        printf("\n");
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '1')
                assert(false);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}