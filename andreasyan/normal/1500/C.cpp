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
const int N = 1503;

int n, m;
int a[N][N], b[N][N];

struct mysort
{
    int c[N] = {}, p[N] = {};
    int q[N] = {}, pp[N] = {}, nc[N] = {};
    void go(int a[][N])
    {
        for (int i = 1; i <= n; ++i)
        {
            c[i] = 1;
            p[i] = i;
        }

        for (int j = 1; j <= m; ++j)
        {
            memset(q, 0, sizeof q);
            for (int i = 1; i <= n; ++i)
                q[a[i][j]]++;
            for (int i = 1; i <= n; ++i)
                q[i] += q[i - 1];
            for (int i = 1; i <= n; ++i)
                pp[++q[a[i][j] - 1]] = i;

            memset(q, 0, sizeof q);
            for (int i = 1; i <= n; ++i)
                q[c[i]]++;
            for (int i = 1; i <= n; ++i)
                q[i] += q[i - 1];
            for (int i = 1; i <= n; ++i)
                p[++q[c[pp[i]] - 1]] = pp[i];

            int z = 0;
            for (int i = 1; i <= n; ++i)
            {
                assert(m_p(c[p[i]], m_p(a[p[i]][j], p[i])) >= m_p(c[p[i - 1]], m_p(a[p[i - 1]][j], p[i - 1])));
                if (m_p(c[p[i]], a[p[i]][j]) != m_p(c[p[i - 1]], a[p[i - 1]][j]))
                    nc[p[i]] = ++z;
                else
                    nc[p[i]] = z;
            }

            for (int i = 1; i <= n; ++i)
                c[i] = nc[i];
        }
    }
};

int p[N][N];

bool c[N];

bool cs[N];
int q[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> b[i][j];

    mysort aa, bb;
    aa.go(a);
    bb.go(b);

    for (int i = 1; i <= n; ++i)
    {
        int ia = aa.p[i];
        int ib = bb.p[i];
        bool z = true;
        for (int j = 1; j <= m; ++j)
        {
            if (a[ia][j] != b[ib][j])
            {
                z = false;
                break;
            }
        }
        if (!z)
        {
            cout << "-1\n";
            return;
        }
        b[ib][0] = ia;
    }

    for (int j = 0; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            p[j][i] = p[j][i - 1];
            if (b[i][j] < b[i - 1][j])
                ++p[j][i];
        }
    }

    c[n] = true;
    for (int j = 1; j <= m; ++j)
    {
        if (p[j][n] - p[j][1] == 0)
            q[j] = 0;
        else
            q[j] = 1;
    }

    vector<int> ans;
    while (1)
    {
        bool z = true;
        int u = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
            {
                if (p[0][i] - p[0][u])
                {
                    z = false;
                    break;
                }
                u = i + 1;
            }
        }
        if (z)
        {
            reverse(all(ans));
            cout << sz(ans) << "\n";
            for (int i = 0; i < sz(ans); ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            return;
        }

        for (int j = 1; j <= m; ++j)
        {
            if (cs[j])
                continue;
            if (q[j] == 0)
            {
                int u = 1;
                for (int i = 1; i <= n; ++i)
                {
                    if (b[i][j] != b[i + 1][j])
                    {
                        if (c[i])
                        {
                            u = i + 1;
                            continue;
                        }
                        c[i] = true;
                        int uu = i + 1;
                        while (!c[uu])
                            ++uu;
                        for (int jj = 1; jj <= m; ++jj)
                        {
                            if (p[jj][uu] - p[jj][u] == 0)
                                continue;
                            ++q[jj];
                            if (p[jj][i] - p[jj][u] == 0)
                                --q[jj];
                            if (p[jj][uu] - p[jj][i + 1] == 0)
                                --q[jj];
                        }
                        u = i + 1;
                    }
                }

                ans.push_back(j);
                cs[j] = true;
                z = true;
                break;
            }
        }

        if (!z)
        {
            cout << "-1\n";
            return;
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}