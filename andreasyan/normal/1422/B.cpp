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
const int N = 102;

int n, m;
int a[N][N];

vector<int> v;
bool c[N][N];
void dfs(int x, int y)
{
    if (c[x][y])
        return;
    c[x][y] = true;
    v.push_back(a[x][y]);
    dfs(n - x + 1, y);
    dfs(x, m - y + 1);
    dfs(n - x + 1, m - y + 1);
}

void solv()
{
    memset(c, false, sizeof c);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            v.clear();
            dfs(i, j);
            sort(all(v));
            for (int i = 0; i < sz(v); ++i)
                ans += abs(v[i] - v[sz(v) / 2]);
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}