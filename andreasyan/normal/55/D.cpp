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
const int M = 2520, K = 48;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int lca(int x, int y)
{
    return x / gcd(x, y) * y;
}

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

vector<int> v;
vector<int> vv[K];

void pre()
{
    // 2 3 5 7
    for (int i2 = 0; i2 <= 3; ++i2)
    {
        for (int i3 = 0; i3 <= 2; ++i3)
        {
            for (int i5 = 0; i5 <= 1; ++i5)
            {
                for (int i7 = 0; i7 <= 1; ++i7)
                {
                    v.push_back(ast(2, i2) * ast(3, i3) * ast(5, i5) * ast(7, i7));
                }
            }
        }
    }
    sort(all(v));
    for (int i = 0; i < v.size(); ++i)
    {
        vv[i].assign(10, 0);
        vv[i][0] = i;
        for (int j = 1; j <= 9; ++j)
        {
            vv[i][j] = lower_bound(all(v), lca(v[i], j)) - v.begin();
        }
    }
}

ll dp[20][M][K];

bool stg(ll y)
{
    vector<int> vx;
    ll x = y;
    while (x)
    {
        vx.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0; i < vx.size(); ++i)
    {
        if (!vx[i])
            continue;
        if (y % vx[i] != 0)
            return false;
    }
    return true;
}

ll solvv0(ll x)
{
    ll ans = 0;
    for (ll i = 1; i <= x; ++i)
    {
        if (stg(i))
            ++ans;
    }
    return ans;
}

ll solvv(ll x)
{
    if (x == 0)
        return 0;
    vector<int> vx;
    while (x)
    {
        vx.push_back(x % 10);
        x /= 10;
    }
    reverse(all(vx));
    memset(dp, 0, sizeof dp);
    int m1 = 0;
    int j1 = 0;
    for (int i = 0; i < vx.size(); ++i)
    {
        for (int m = 0; m < M; ++m)
        {
            for (int j = 0; j < v.size(); ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    dp[i + 1][(m * 10 + k) % M][vv[j][k]] += dp[i][m][j];
                }
            }
        }
        for (int k = 0; k < vx[i]; ++k)
        {
            dp[i + 1][(m1 * 10 + k) % M][vv[j1][k]]++;
        }
        m1 = (m1 * 10 + vx[i]) % M;
        j1 = vv[j1][vx[i]];
    }
    ll ans = 0;
    for (int m = 0; m < M; ++m)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            if ((m % v[j]) == 0)
                ans += dp[vx.size()][m][j];
        }
    }
    if (m1 % v[j1] == 0)
        ++ans;
    return ans - 1;
}

ll solv0(ll l, ll r)
{
    return solvv0(r) - solvv0(l - 1);
}

ll solv(ll l, ll r)
{
    return solvv(r) - solvv(l - 1);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        //printf("%lld\n", solv0(l, r));
        printf("%lld\n", solv(l, r));
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}