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
const int N = 55;
const int xx[4] = {1, 0, -1, 0};
const int yy[4] = {0, 1, 0, -1};

int n, m;
int a[N][N];
int b[N][N];

void tp()
{
    return;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

struct ban
{
    int x1, y1_, x2, y2;
    ban(){}
    ban(int x1, int y1_, int x2, int y2)
    {
        this->x1 = x1;
        this->y1_ = y1_;
        this->x2 = x2;
        this->y2 = y2;
    }
};
vector<ban> ans;

void ubd(int x1, int y1_, int x2, int y2)
{
    assert(1 <= x1 && x1 <= n);
    assert(1 <= y1_ && y1_ <= n);
    assert(1 <= x2 && x2 <= n);
    assert(1 <= y2 && y2 <= n);

    assert(!a[x2][y2]);
    assert(a[x1][y1_]);

    ans.push_back(ban(x1, y1_, x2, y2));
    a[x2][y2] = a[x1][y1_];
    a[x1][y1_] = 0;
}

int u[N];

bool c[N][N];
pair<int, int> p[N][N];
vector<pair<int, int> > bfs(int x1, int y1_, int x2, int y2)
{
    memset(c, false, sizeof c);

    queue<pair<int, int> > q;
    c[x1][y1_] = true;
    q.push(m_p(x1, y1_));
    while (!q.empty())
    {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        if (m_p(x, y) == m_p(x2, y2))
        {
            vector<pair<int, int> > v;
            while (m_p(x, y) != m_p(x1, y1_))
            {
                v.push_back(m_p(x, y));
                int hx = p[x][y].fi;
                int hy = p[x][y].se;
                x = hx;
                y = hy;
            }
            v.push_back(m_p(x, y));
            reverse(all(v));
            return v;
        }

        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (1 <= hx && hx <= n && 1 <= hy && hy <= n && !c[hx][hy] && !a[hx][hy])
            {
                c[hx][hy] = true;
                p[hx][hy] = m_p(x, y);
                q.push(m_p(hx, hy));
            }
        }
    }
    assert(false);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        b[x][y] = i;
    }

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    tp();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j])
            {
                for (int k = j; k > 1; --k)
                {
                    if (a[i][k - 1])
                        break;
                    ubd(i, k, i, k - 1);
                }
            }
        }
    }

    tp();

    while (1)
    {
        int maxu = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = n; j >= 1; --j)
            {
                if (a[i][j])
                {
                    maxu = max(maxu, j);
                    break;
                }
            }
        }

        if (maxu == 1)
            break;

        for (int i = 1; i <= n; ++i)
        {
            if (!a[i][1])
            {
                bool z = false;
                for (int k = i + 1; k <= n; ++k)
                {
                    if (a[k][maxu])
                    {
                        while (k > i)
                        {
                            ubd(k, maxu, k - 1, maxu);
                            --k;
                        }
                        for (int j = maxu; j > 1; --j)
                            ubd(i, j, i, j - 1);
                        z = true;
                        break;
                    }
                }
                if (z)
                    break;

                for (int k = i - 1; k >= 1; --k)
                {
                    if (a[k][maxu])
                    {
                        while (k < i)
                        {
                            ubd(k, maxu, k + 1, maxu);
                            ++k;
                        }
                        for (int j = maxu; j > 1; --j)
                            ubd(i, j, i, j - 1);
                        z = true;
                        break;
                    }
                }
                assert(z);
                break;
            }
        }
    }

    tp();

    int z = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (b[i][j])
                u[b[i][j]] = ++z;
        }
    }

    for (int x = 1; x <= m; ++x)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (u[a[i][1]] >= x)
            {
                if (u[a[i][1]] == x)
                    break;
                for (int k = i + 1; k <= n; ++k)
                {
                    if (u[a[k][1]] == x)
                    {
                        if (n > 2)
                        {
                            ubd(i, 1, i, 2);
                            ubd(i, 2, i, 3);

                            ubd(k, 1, k, 2);
                            for (int t = k; t > i; --t)
                                ubd(t, 2, t - 1, 2);
                            ubd(i, 2, i, 1);

                            ubd(i, 3, i, 2);
                            for (int t = i; t < k; ++t)
                                ubd(t, 2, t + 1, 2);
                            ubd(k, 2, k, 1);
                        }
                        else
                        {
                            ubd(i, 1, i, 2);

                            for (int t = k; t > i; --t)
                                ubd(t, 1, t - 1, 1);

                            for (int t = i; t < k; ++t)
                                ubd(t, 2, t + 1, 2);
                            ubd(k, 2, k, 1);
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    tp();

    for (int j = 1; j <= n; ++j)
    {
        set<int> s;
        for (int i = 1; i <= n; ++i)
        {
            s.insert(b[i][j]);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] && s.find(a[i][j]) == s.end())
                ubd(i, j, i, j + 1);
        }
    }

    for (int j = 1; j <= n; ++j)
    {
        while (1)
        {
            bool z = true;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i][j] != b[i][j])
                {
                    z = false;
                    break;
                }
            }
            if (z)
                break;

            for (int i = 1; i <= n; ++i)
            {
                if (a[i][j])
                {
                    if (a[i][j] == b[i][j])
                        continue;

                    bool z = false;
                    for (int k = i + 1; k <= n; ++k)
                    {
                        if (a[k][j])
                            break;
                        if (b[k][j] == a[i][j])
                        {
                            while (i < k)
                            {
                                ubd(i, j, i + 1, j);
                                ++i;
                            }
                            z = true;
                            break;
                        }
                    }
                    if (z)
                        break;

                    for (int k = i - 1; k >= 1; --k)
                    {
                        if (a[k][j])
                            break;
                        if (b[k][j] == a[i][j])
                        {
                            while (i > k)
                            {
                                ubd(i, j, i - 1, j);
                                --i;
                            }
                            z = true;
                            break;
                        }
                    }
                    if (z)
                        break;
                }
            }
        }
    }

    tp();

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].x1 << ' ' << ans[i].y1_ << ' ' << ans[i].x2 << ' ' << ans[i].y2 << "\n";
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