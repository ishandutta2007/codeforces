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
const int N = 503;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, k;
char a[N][N];

int yq[N * N], q[N * N];

int c[N][N];
int z;
void dfs(int x, int y)
{
    c[x][y] = z;
    ++yq[z];
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (a[hx][hy] == '.' && !c[hx][hy])
        {
            dfs(hx, hy);
        }
    }
}

bool cc[N * N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == '.' && !c[i][j])
            {
                ++z;
                dfs(i, j);
            }
        }
    }
    int ans = 0;
    for (int l = 1; l <= n - k + 1; ++l)
    {
        int r = l + k - 1;
        memset(q, 0, sizeof q);
        for (int i = 1; i <= k; ++i)
        {
            for (int j = l; j <= r; ++j)
            {
                ++q[c[i][j]];
            }
        }
        for (int u = 1; u <= n - k + 1; ++u)
        {
            int d = u + k - 1;
            int yans = k * k;
            for (int i = u; i <= d; ++i)
            {
                if (c[i][l - 1] && !cc[c[i][l - 1]])
                {
                    yans += yq[c[i][l - 1]];
                    yans -= q[c[i][l - 1]];
                    cc[c[i][l - 1]] = true;
                }
                if (c[i][r + 1] && !cc[c[i][r + 1]])
                {
                    yans += yq[c[i][r + 1]];
                    yans -= q[c[i][r + 1]];
                    cc[c[i][r + 1]] = true;
                }
            }
            for (int j = l; j <= r; ++j)
            {
                if (c[u - 1][j] && !cc[c[u - 1][j]])
                {
                    yans += yq[c[u - 1][j]];
                    yans -= q[c[u - 1][j]];
                    cc[c[u - 1][j]] = true;
                }
                if (c[d + 1][j] && !cc[c[d + 1][j]])
                {
                    yans += yq[c[d + 1][j]];
                    yans -= q[c[d + 1][j]];
                    cc[c[d + 1][j]] = true;
                }
            }
            ans = max(ans, yans);
            for (int i = u; i <= d; ++i)
            {
                cc[c[i][l - 1]] = false;
                cc[c[i][r + 1]] = false;
            }
            for (int i = l; i <= r; ++i)
            {
                cc[c[u - 1][i]] = false;
                cc[c[d + 1][i]] = false;
            }
            for (int j = l; j <= r; ++j)
            {
                --q[c[u][j]];
                ++q[c[d + 1][j]];
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}