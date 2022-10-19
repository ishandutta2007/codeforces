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
const int N = 400005;

int n, m, qq;
vector<int> g[N];

bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
}

void solv()
{
    cin >> n >> m >> qq;
    for (int i = 0; i < qq; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(n + y);
        g[n + y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n + m; ++i)
    {
        if (!c[i])
        {
            ++ans;
            dfs(i);
        }
    }
    --ans;

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