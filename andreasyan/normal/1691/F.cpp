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
const int M = 1000000007;

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
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

int n, k;
vector<int> g[N];

vector<int> gg[N];
int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
        {
            gg[x].push_back(n - q[x]);
            continue;
        }
        gg[x].push_back(q[h]);
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);

    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        vector<int> u;
        u.assign(sz(g[x]), 0);
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (n - gg[x][i] < k)
                continue;

            int yans = (gg[x][i] * 1LL * (n - gg[x][i])) % M;
            u[0] = (u[0] + yans) % M;
            u[i] = (u[i] - yans + M) % M;
            if (i + 1 < sz(u))
                u[i + 1] = (u[i + 1] + yans) % M;

            yans = (yans * 1LL * C(n - gg[x][i], k)) % M;
            ans = (ans + yans) % M;
        }

        for (int i = 0; i < g[x].size(); ++i)
        {
            if (i)
                u[i] = (u[i] + u[i - 1]) % M;
            if (gg[x][i] >= k)
            {
                ans = (ans - u[i] * 1LL * C(gg[x][i], k)) % M;
                ans = (ans + M) % M;
            }
        }

        ans = (ans + C(n, k) * 1LL * n) % M;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (gg[x][i] >= k)
            {
                ans = (ans - C(gg[x][i], k) * 1LL * n) % M;
                ans = (ans + M) % M;
            }
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

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}