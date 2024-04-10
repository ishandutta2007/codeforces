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
const int N = 400005;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
vector<vector<int> > a, q;
int q0;

void han(int x, int y)
{
    if (q[x][y] == 0)
        --q0;
}

void ave(int x, int y)
{
    q[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (a[x][y] > a[hx][hy])
            ++q[x][y];
    }
    if (q[x][y] == 0)
        ++q0;
}

void solv()
{
    cin >> n >> m;

    a.assign(n + 5, {});
    q.assign(n + 5, {});
    for (int i = 0; i < n + 5; ++i)
    {
        a[i].assign(m + 5, N);
        q[i].assign(m + 5, N);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            ave(x, y);
        }
    }

    if (q0 == 1)
    {
        cout << "0\n";
        return;
    }

    vector<pair<int, int> > v;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            if (q[x][y] == 0 && a[x][y] > 1)
            {
                v.push_back(m_p(x, y));
                for (int i = 0; i < 4; ++i)
                {
                    int hx = x + xx[i];
                    int hy = y + yy[i];
                    if (1 <= hx && hx <= n && 1 <= hy && hy <= m)
                        v.push_back(m_p(hx, hy));
                }
                break;
            }
        }
        if (!v.empty())
            break;
    }

    sort(all(v));

    int ans = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        int x1 = v[i].fi;
        int y1_ = v[i].se;
        for (int x2 = 1; x2 <= n; ++x2)
        {
            for (int y2 = 1; y2 <= m; ++y2)
            {
                if (x1 == x2 && y1_ == y2)
                    continue;
                if (binary_search(all(v), m_p(x2, y2)))
                {
                    if (a[x1][y1_] > a[x2][y2])
                        continue;
                }

                vector<pair<int, int> > v;
                v.push_back(m_p(x1, y1_));
                for (int i = 0; i < 4; ++i)
                {
                    int hx = x1 + xx[i];
                    int hy = y1_ + yy[i];
                    if (1 <= hx && hx <= n && 1 <= hy && hy <= m)
                        v.push_back(m_p(hx, hy));
                }
                v.push_back(m_p(x2, y2));
                for (int i = 0; i < 4; ++i)
                {
                    int hx = x2 + xx[i];
                    int hy = y2 + yy[i];
                    if (1 <= hx && hx <= n && 1 <= hy && hy <= m)
                        v.push_back(m_p(hx, hy));
                }
                sort(all(v));

                for (int i = 0; i < sz(v); ++i)
                {
                    if (i == 0 || v[i] != v[i - 1])
                        han(v[i].fi, v[i].se);
                }
                swap(a[x1][y1_], a[x2][y2]);
                for (int i = 0; i < sz(v); ++i)
                {
                    if (i == 0 || v[i] != v[i - 1])
                        ave(v[i].fi, v[i].se);
                }

                if (q0 == 1)
                    ++ans;

                for (int i = 0; i < sz(v); ++i)
                {
                    if (i == 0 || v[i] != v[i - 1])
                        han(v[i].fi, v[i].se);
                }
                swap(a[x1][y1_], a[x2][y2]);
                for (int i = 0; i < sz(v); ++i)
                {
                    if (i == 0 || v[i] != v[i - 1])
                        ave(v[i].fi, v[i].se);
                }
            }
        }
    }

    if (ans == 0)
        cout << "2\n";
    else
        cout << "1 " << ans << "\n";
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