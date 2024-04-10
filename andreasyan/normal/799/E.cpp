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
const ll INF = 1000000009000000009;

int n, m, k;
int c[N];
int u[N];

void ka()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x;
        cin >> x;
        u[x]++;
    }

    cin >> qq;
    while (qq--)
    {
        int x;
        cin >> x;
        u[x] += 2;
    }
}

vector<int> v[4];

ll solv()
{

    for (int i = 0; i < 4; ++i)
        v[i].clear();

    for (int i = 1; i <= n; ++i)
    {
        v[u[i]].push_back(c[i]);
    }

    for (int i = 0; i < 4; ++i)
    {
        sort(all(v[i]));
        while (sz(v[i]) > m)
            v[i].pop_back();
    }

    ll ans = INF;

    ll yans = 0;
    for (int i = 0; i < sz(v[3]); ++i)
        yans += v[3][i];

    int i[4] = {};
    for (i[3] = sz(v[3]); i[3] >= 0; --i[3])
    {
        if (i[3] < sz(v[3]))
            yans -= v[3][i[3]];

        int p = max(0, k - i[3]);

        bool z = true;
        while (i[2] < p)
        {
            if (i[2] == sz(v[2]))
            {
                z = false;
                break;
            }
            yans += v[2][i[2]++];
            if (i[3] + i[2] + i[1] + i[0] > m)
            {
                ll maxu = -INF;
                for (int j = 0; j < 3; ++j)
                {
                    if (i[j] - 1 >= 0 && (j == 0 || i[j] > p))
                        maxu = max(maxu, 1LL * v[j][i[j] - 1]);
                }
                if (maxu == -INF)
                {
                    z = false;
                    break;
                }
                for (int j = 0; j < 3; ++j)
                {
                    if (i[j] - 1 >= 0 && (j == 0 || i[j] > p))
                    {
                        if (maxu == v[j][i[j] - 1])
                        {
                            yans -= v[j][i[j] - 1];
                            --i[j];
                            break;
                        }
                    }
                }
            }
        }
        if (!z)
            break;

        while (i[1] < p)
        {
            if (i[1] == sz(v[1]))
            {
                z = false;
                break;
            }
            yans += v[1][i[1]++];
            if (i[3] + i[2] + i[1] + i[0] > m)
            {
                ll maxu = -INF;
                for (int j = 0; j < 3; ++j)
                {
                    if (i[j] - 1 >= 0 && (j == 0 || i[j] > p))
                        maxu = max(maxu, 1LL * v[j][i[j] - 1]);
                }
                if (maxu == -INF)
                {
                    z = false;
                    break;
                }
                for (int j = 0; j < 3; ++j)
                {
                    if (i[j] - 1 >= 0 && (j == 0 || i[j] > p))
                    {
                        if (maxu == v[j][i[j] - 1])
                        {
                            yans -= v[j][i[j] - 1];
                            --i[j];
                            break;
                        }
                    }
                }
            }
        }
        if (!z)
            break;

        while (i[3] + i[2] + i[1] + i[0] < m)
        {
            ll minu = INF;
            for (int j = 0; j < 3; ++j)
            {
                if (i[j] != sz(v[j]))
                    minu = min(minu, 1LL * v[j][i[j]]);
            }
            if (minu == INF)
            {
                z = false;
                break;
            }
            for (int j = 0; j < 3; ++j)
            {
                if (i[j] != sz(v[j]))
                {
                    if (minu == v[j][i[j]])
                    {
                        yans += minu;
                        ++i[j];
                        break;
                    }
                }
            }
        }
        if (!z)
            break;

        if (i[0] + i[1] + i[2] + i[3] == m)
            ans = min(ans, yans);
    }

    return ans;
}

ll solv0()
{
    ll ans = INF;
    for (int i = 0; i <= sz(v[3]); ++i)
    {
        int p = max(0, k - i);

        if (p > sz(v[2]) || p > sz(v[1]))
            continue;

        if (i + p + p > m)
            continue;

        ll yans = 0;
        for (int j = 0; j < i; ++j)
            yans += v[3][j];

        for (int j = 0; j < p; ++j)
            yans += v[2][j];
        for (int j = 0; j < p; ++j)
            yans += v[1][j];

        vector<int> u;
        for (int j = p; j < sz(v[2]); ++j)
            u.push_back(v[2][j]);
        for (int j = p; j < sz(v[1]); ++j)
            u.push_back(v[1][j]);
        for (int j = 0; j < sz(v[0]); ++j)
            u.push_back(v[0][j]);
        sort(all(u));

        if (m - i - p - p > sz(u))
            continue;

        for (int j = 0; j < m - i - p - p; ++j)
            yans += u[j];

        ans = min(ans, yans);
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 1000;
    while (st--)
    {
        n = rnf() % 100 + 1;
        m = rnf() % n + 1;
        k = rnf() % n + 1;
        for (int i = 1; i <= n; ++i)
            u[i] = rnf() % 4;
        for (int i = 1; i <= n; ++i)
            c[i] = rnf() % 9 + 1;
        if (solv() != solv0())
        {
            cout << "WA\n";
            cout << n << ' ' << m << ' ' << k << "\n";
            for (int i = 1; i <= n; ++i)
                cout << u[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n; ++i)
                cout << c[i] << ' ';
            cout << "\n";
            cout << "Wrong answer: " << solv() << "\n";
            cout << "Correct answer: " << solv0() << "\n";
            return 0;
        }
    }
    cout << "OK\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        ka();
        ll ans = solv();
        if (ans == INF)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
    return 0;
}