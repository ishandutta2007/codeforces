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

int n;
vector<pair<int, int> > g[N];

int c[N];

int q[N];
void dfs(int x, int u)
{
    while (!g[x].empty() && c[g[x].back().se])
        g[x].pop_back();
    if (g[x].empty())
        return;
    c[g[x].back().se] = u;
    --q[x];
    --q[g[x].back().fi];
    dfs(g[x].back().fi, 3 - u);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(m_p(N / 2 + y, i));
        g[N / 2 + y].push_back(m_p(x, i));
    }
    for (int x = 0; x < N; ++x)
        q[x] = sz(g[x]);
    for (int x = 0; x < N; ++x)
    {
        if (q[x] % 2 == 1)
            dfs(x, 1);
    }
    for (int x = 0; x < N; ++x)
    {
        while (1)
        {
            if (!q[x])
                break;
            dfs(x, 1);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        if (c[x] == 1)
            printf("b");
        else
            printf("r");
    }
    printf("\n");
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