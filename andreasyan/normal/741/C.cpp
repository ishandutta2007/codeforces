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

int n;
pair<int, int> b[N];
vector<int> g[N];

int c[N];
void dfs(int x, int u)
{
    c[x] = u;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h, 3 - u);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        b[i] = m_p(x, y);
    }
    for (int i = 1; i <= n * 2; i += 2)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    for (int i = 1; i <= n * 2; ++i)
    {
        if (!c[i])
            dfs(i, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d %d\n", c[b[i].fi], c[b[i].se]);
    }
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