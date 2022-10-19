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
const int N = 100005;

int n;
int l[N], r[N];
vector<int> g[N];

ll dp[N][2];
void dfs(int x, int p)
{
    dp[x][0] = dp[x][1] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x][0] = max(dp[x][0] + dp[h][0] + abs(l[x] - l[h]), dp[x][0] + dp[h][1] + abs(l[x] - r[h]));
        dp[x][1] = max(dp[x][1] + dp[h][0] + abs(r[x] - l[h]), dp[x][1] + dp[h][1] + abs(r[x] - r[h]));
    }
}

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int x = 1; x <= n; ++x)
        cin >> l[x] >> r[x];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}