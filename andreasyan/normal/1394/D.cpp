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

ll ans;

int n;
int t[N], h[N];
vector<int> g[N];

int in[N], out[N];

bool c[N];

ll dp[N][2];
void dfs(int x, int p)
{
    c[x] = true;
    vector<ll> v;
    ll s = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        s += dp[h][0];
        v.push_back(dp[h][1] - dp[h][0]);
    }
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i <= sz(v); ++i)
    {
        if (i)
            s += v[i - 1];
        if (x != p)
        {
            dp[x][0] = max(dp[x][0], s + min(in[x] + i + 1, out[x] + sz(v) - i) * 1LL * t[x]);
            dp[x][1] = max(dp[x][1], s + min(in[x] + i, out[x] + sz(v) - i + 1) * 1LL * t[x]);
        }
        else
        {
            dp[x][0] = max(dp[x][0], s + min(in[x] + i, out[x] + sz(v) - i) * 1LL * t[x]);
        }
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ans += t[x];
        ans += t[y];
        if (h[x] == h[y])
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        else
        {
            if (h[x] < h[y])
            {
                out[x]++;
                in[y]++;
            }
            else
            {
                out[y]++;
                in[x]++;
            }
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs(x, x);
            ans -= dp[x][0];
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}