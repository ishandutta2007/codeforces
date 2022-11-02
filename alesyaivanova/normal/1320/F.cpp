#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

struct kek
{
    int x, y, z;
    kek(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {};
};

const int maxn = 1e6 + 9;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<bool> > > used(n);
    for (int i = 0; i < n; i++)
    {
        used[i].resize(m);
        for (int e = 0; e < m; e++)
            used[i][e].resize(k, 1);
    }

    int sz = 2;
    vector<vector<vector<int> > > cx(2);
    vector<vector<vector<int> > > cy(2);
    vector<vector<vector<int> > > cz(2);
    vector<vector<vector<int> > > ptx(2);
    vector<vector<vector<int> > > pty(2);
    vector<vector<vector<int> > > ptz(2);
    queue<kek> q;

    for (int j = 0; j <= 1; j++)
    {
        cx[j].resize(m);
        ptx[j].resize(m);
        for (int i = 0; i < m; i++)
        {
            cx[j][i].resize(k);
            ptx[j][i].resize(k, 0);
            for (int e = 0; e < k; e++)
            {
                cin >> cx[j][i][e];
                if (j)
                    ptx[1][i][e] = n - 1;
                if (!cx[j][i][e])
                    q.emplace(ptx[j][i][e], i, e);
            }
        }
    }
    for (int j = 0; j <= 1; j++)
    {
        cy[j].resize(n);
        pty[j].resize(n);
        for (int i = 0; i < n; i++)
        {
            cy[j][i].resize(k);
            pty[j][i].resize(k, 0);
            for (int e = 0; e < k; e++)
            {
                cin >> cy[j][i][e];
                if (j)
                    pty[1][i][e] = m - 1;
                if (!cy[j][i][e])
                    q.emplace(i, pty[j][i][e], e);
            }
        }
    }
    for (int j = 0; j <= 1; j++)
    {
        cz[j].resize(n);
        ptz[j].resize(n);
        for (int i = 0; i < n; i++)
        {
            cz[j][i].resize(m);
            ptz[j][i].resize(m, 0);
            for (int e = 0; e < m; e++)
            {
                cin >> cz[j][i][e];
                if (j)
                    ptz[1][i][e] = k - 1;
                if (!cz[j][i][e])
                    q.emplace(i, e, ptz[j][i][e]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cz[0][i][0] != cy[0][i][0])
            q.emplace(i, 0, 0);
        if (cz[1][i][0] != cy[0][i][k - 1])
            q.emplace(i, 0, k - 1);
        if (cz[0][i][m - 1] != cy[1][i][0])
            q.emplace(i, m - 1, 0);
        if (cz[1][i][m - 1] != cy[1][i][k - 1])
            q.emplace(i, m - 1, k - 1);
    }

    for (int e = 0; e < m; e++)
    {
        if (cz[0][0][e] != cx[0][e][0])
            q.emplace(0, e, 0);
        if (cz[1][0][e] != cx[0][e][k - 1])
            q.emplace(0, e, k - 1);
        if (cz[0][n - 1][e] != cx[1][e][0])
            q.emplace(n - 1, e, 0);
        if (cz[1][n - 1][e] != cx[1][e][k - 1])
            q.emplace(n - 1, e, k - 1);
    }

    for (int j = 0; j < k; j++)
    {
        if (cx[0][0][j] != cy[0][0][j])
            q.emplace(0, 0, j);
        if (cx[1][0][j] != cy[0][n - 1][j])
            q.emplace(n - 1, 0, j);
        if (cx[0][m - 1][j] != cy[1][0][j])
            q.emplace(0, m - 1, j);
        if (cx[1][m - 1][j] != cy[1][n - 1][j])
            q.emplace(n - 1, m - 1, j);
    }

    if (n == 1)
    {
        for (int e = 0; e < m; e++)
        {
            for (int j = 0; j < k; j++)
            {
                if (cx[0][e][j] != cx[1][e][j])
                    q.emplace(0, e, j);
            }
        }
    }

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (cy[0][i][j] != cy[1][i][j])
                    q.emplace(i, 0, j);
            }
        }
    }

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int e = 0; e < m; e++)
            {
                if (cz[0][i][e] != cz[1][i][e])
                    q.emplace(i, e, 0);
            }
        }
    }

    auto check = [&](int i, int e, int j)
    {
        set<int> s;
        for (int t = 0; t <= 1; t++)
        {
            if (ptx[t][e][j] == i)
                s.insert(cx[t][e][j]);
            if (pty[t][i][j] == e)
                s.insert(cy[t][i][j]);
            if (ptz[t][i][e] == j)
                s.insert(cz[t][i][e]);
        }
        return s.find(0) != s.end() || s.size() >= 2;
    };

    auto check1 = [&](int i, int e, int j)
    {
        set<int> s;
        for (int t = 0; t <= 1; t++)
        {
            if (ptx[t][e][j] == i)
                s.insert(cx[t][e][j]);
            if (pty[t][i][j] == e)
                s.insert(cy[t][i][j]);
            if (ptz[t][i][e] == j)
                s.insert(cz[t][i][e]);
        }
        if (!used[i][e][j])
        {
            if (s.empty() || ((int)s.size() == 1 && (*s.begin()) == 0))
                return 0ll;
            return -1ll;
        }
        if (s.find(0) != s.end())
            return -1ll;
        if (s.empty())
            return 0ll;
        if ((int)s.size() >= 2)
            return -1ll;
        return (*s.begin());
    };

    while (!q.empty())
    {
        kek cur = q.front();
        q.pop();
        int i = cur.x;
        int e = cur.y;
        int j = cur.z;
        if (!used[i][e][j])
            continue;
        used[i][e][j] = 0;

        if (ptx[0][e][j] == i && ptx[1][e][j] == i)
        {
            if (cx[0][e][j] || cx[1][e][j])
            {
                cout << -1;
                return 0;
            }
        }
        else if (ptx[0][e][j] == i)
        {
            while (!used[ptx[0][e][j]][e][j])
                ptx[0][e][j]++;
            if (check(ptx[0][e][j], e, j))
                q.emplace(ptx[0][e][j], e, j);
        }
        else if (ptx[1][e][j] == i)
        {
            while (!used[ptx[1][e][j]][e][j])
                ptx[1][e][j]--;
            if (check(ptx[1][e][j], e, j))
                q.emplace(ptx[1][e][j], e, j);
        }

        if (pty[0][i][j] == e && pty[1][i][j] == e)
        {
            if (cy[0][i][j] || cy[1][i][j])
            {
                cout << -1;
                return 0;
            }
        }
        else if (pty[0][i][j] == e)
        {
            while (!used[i][pty[0][i][j]][j])
                pty[0][i][j]++;
            if (check(i, pty[0][i][j], j))
                q.emplace(i, pty[0][i][j], j);
        }
        else if (pty[1][i][j] == e)
        {
            while (!used[i][pty[1][i][j]][j])
                pty[1][i][j]--;
            if (check(i, pty[1][i][j], j))
                q.emplace(i, pty[1][i][j], j);
        }

        if (ptz[0][i][e] == j && ptz[1][i][e] == j)
        {
            if (cz[0][i][e] || cz[1][i][e])
            {
                cout << -1;
                return 0;
            }
        }
        else if (ptz[0][i][e] == j)
        {
            while (!used[i][e][ptz[0][i][e]])
                ptz[0][i][e]++;
            if (check(i, e, ptz[0][i][e]))
                q.emplace(i, e, ptz[0][i][e]);
        }
        else if (ptz[1][i][e] == j)
        {
            while (!used[i][e][ptz[1][i][e]])
                ptz[1][i][e]--;
            if (check(i, e, ptz[1][i][e]))
                q.emplace(i, e, ptz[1][i][e]);
        }
    }
    int ans[n][m][k] = {};
    for (int i = 0; i < n; i++)
        for (int e = 0; e < m; e++)
            for (int j = 0; j < k; j++)
            {
                ans[i][e][j] = check1(i, e, j);
                if (ans[i][e][j] == -1)
                {
                    cout << -1;
                    return 0;
                }
            }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            for (int j = 0; j < k; j++)
                cout << ans[i][e][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}