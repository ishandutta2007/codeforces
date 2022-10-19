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
const int N = 502, INF = 1000000009;

int n, m;
vector<pair<int, int> > a[N];

int d[N][N];

int q[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            d[i][j] = INF;
        }
    }
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        d[x][y] = z;
        d[y][x] = z;
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    for (int z = 1; z <= n; ++z)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                d[x][y] = min(d[x][y], d[x][z] + d[z][y]);
            }
        }
    }
    for (int s = 1; s <= n; ++s)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int i = 0; i < a[x].size(); ++i)
            {
                if (d[s][x] == d[s][a[x][i].fi] + a[x][i].se)
                    ++q[s][x];
            }
        }
    }
    for (int s = 1; s <= n; ++s)
    {
        for (int f = s + 1; f <= n; ++f)
        {
            int ans = 0;
            for (int x = 1; x <= n; ++x)
            {
                if (d[s][f] == d[s][x] + d[x][f])
                    ans += q[s][x];
            }
            printf("%d ", ans);
        }
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