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
const int N = 300005, M2 = 22, M = 998244353;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    return ((f[n] * 1LL * rf[k]) % M * 1LL * rf[n - k]) % M;
}

int n, m;
int l[N], r[N];
pair<int, int> b[M2];

bool c[N];
vector<int> u;
int ru[N];

int q[N];

vector<int> v[N];
bool cc[M2 * 2];

int dp[M2][(1 << M2)];
int q0[M2 * 2];
void clc()
{
    memset(q0, 0, sizeof q0);
    memset(dp, 0, sizeof dp);

    vector<pair<int, int> > b;

    int z = 0;
    int h[M2 * 2] = {};
    for (int i = 0; i < sz(u); ++i)
    {
        if (cc[i])
        {
            h[i] = z++;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (!cc[::b[i].fi] || !cc[::b[i].se])
            continue;
        b.push_back(m_p(h[::b[i].fi], h[::b[i].se]));
    }

    vector<int> u(z);

    bool cc[M2 * 2];
    for (int i = 0; i < M2 * 2; ++i)
        cc[i] = true;
    for (int x = 0; x < (1 << (sz(u) / 2)); ++x)
    {
        int q = 0;
        bool z = true;
        for (int i = 0; i < sz(u) / 2; ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
                if (!cc[i])
                {
                    z = false;
                    break;
                }
            }
        }
        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i].fi < sz(u) / 2 && b[i].se < sz(u) / 2)
            {
                if ((x & (1 << b[i].fi)) && (x & (1 << b[i].se)))
                {
                    z = false;
                    break;
                }
            }
        }
        if (!z)
            continue;
        int y = 0;
        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i].fi > b[i].se)
                swap(b[i].fi, b[i].se);
            if (b[i].fi < sz(u) / 2 && b[i].se >= sz(u) / 2)
            {
                if ((x & (1 << b[i].fi)))
                    y |= (1 << (b[i].se - sz(u) / 2));
            }
        }
        for (int i = 0; i < sz(u) / 2 + sz(u) % 2; ++i)
        {
            if (!(y & (1 << i)))
                y += (1 << i);
            else
                y -= (1 << i);
        }
        dp[q][y]++;
    }

    for (int q1 = 0; q1 <= sz(u) / 2; ++q1)
    {
        for (int i = 0; i < sz(u) / 2 + sz(u) % 2; ++i)
        {
            for (int x = (1 << (sz(u) / 2 + sz(u) % 2)) - 1; x >= 0; --x)
            {
                if (!(x & (1 << i)))
                    dp[q1][x] = (dp[q1][x] + dp[q1][(x ^ (1 << i))]);
            }
        }
    }

    for (int x = 0; x < (1 << (sz(u) / 2 + sz(u) % 2)); ++x)
    {
        int q = 0;
        bool z = true;
        for (int i = 0; i < sz(u) / 2 + sz(u) % 2; ++i)
        {
            if ((x & (1 << i)))
            {
                if (!cc[i + sz(u) / 2])
                {
                    z = false;
                    break;
                }
                ++q;
            }
        }
        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i].fi >= sz(u) / 2 && b[i].se >= sz(u) / 2)
            {
                if ((x & (1 << (b[i].fi - (sz(u) / 2)))) && (x & (1 << (b[i].se - (sz(u) / 2)))))
                {
                    z = false;
                    break;
                }
            }
        }
        if (!z)
            continue;
        for (int q1 = 0; q1 <= sz(u) / 2; ++q1)
        {
            q0[q + q1] = (q0[q + q1] + dp[q1][x]);
        }
    }
}

void solv()
{
    pre();

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &b[i].fi, &b[i].se);
        c[b[i].fi] = c[b[i].se] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            ru[i] = sz(u);
            u.push_back(i);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        b[i].fi = ru[b[i].fi];
        b[i].se = ru[b[i].se];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            v[l[i]].push_back(ru[i]);
            v[r[i] + 1].push_back(ru[i]);
        }
        else
        {
            q[l[i]]++;
            q[r[i] + 1]--;
        }
    }

    int ans = 0;
    int qq = 0;
    clc();
    for (int i = 1; i <= n; ++i)
    {
        qq += q[i];
        for (int j = 0; j < v[i].size(); ++j)
        {
            cc[v[i][j]] ^= true;
        }
        if (!v[i].empty())
            clc();
        for (int q = 0; q <= m; ++q)
        {
            if (qq >= (i - q))
            {
                ans = (ans + q0[q] * 1LL * C(qq, qq - (i - q))) % M;
            }
        }
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}