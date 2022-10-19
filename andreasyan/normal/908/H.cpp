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
const int N = 50, K = 23;

int n;
char a[N][N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int q[N];

vector<int> v;
int g[N];

ll dp[(1 << 23)];
ll cdp[(1 << 23)];

int qb[(1 << 23)];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> (a[i] + 1);
    }

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 'A')
            {
                kpc(i, j);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 'X')
            {
                if (fi(i) == fi(j))
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        q[fi(i)]++;

    for (int i = 1; i <= n; ++i)
    {
        if (q[i] >= 2)
            v.push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 'X' && q[fi(i)] >= 2 && q[fi(j)] >= 2)
            {
                g[(lower_bound(all(v), fi(i)) - v.begin())] |= (1LL << (lower_bound(all(v), fi(j)) - v.begin()));
            }
        }
    }

    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        dp[x] = 1;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                if ((g[i] & x))
                {
                    dp[x] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < sz(v); ++i)
    {
        for (int x = (1 << sz(v)) - 1; x >= 0; --x)
        {
            if ((x & (1 << i)))
            {
                dp[x] += dp[(x ^ (1 << i))];
                qb[x]++;
            }
        }
    }

    for (int x = 0; x < (1 << sz(v)); ++x)
        cdp[x] = dp[x];

    int ans = n + sz(v) - 1;
    for (int k = 1; k < sz(v); ++k)
    {
        ll t = 0;
        for (int x = 0; x < (1 << sz(v)); ++x)
        {
            if ((sz(v) - qb[x]) % 2 == 0)
                t += dp[x];
            else
                t -= dp[x];
            dp[x] *= cdp[x];
        }

        if (t)
        {
            ans = k + n - 1;
            break;
        }
    }

    cout << ans << "\n";
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