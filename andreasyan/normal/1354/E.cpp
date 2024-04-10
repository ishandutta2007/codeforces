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
const int N = 5003;

int n, m;
int n1, n2, n3;
vector<int> a[N];

int c[N];
vector<int> v;
void dfs(int x, int g)
{
    c[x] = g;
    v.push_back(x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h, 3 - g);
    }
}

vector<pair<vector<int>, vector<int> > > vv;

bool dp[N][N];

int ans[N];
void solv()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d%d", &n1, &n2, &n3);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            v.clear();
            dfs(i, 1);
            for (int j = 0; j < v.size(); ++j)
            {
                int x = v[j];
                for (int k = 0; k < a[x].size(); ++k)
                {
                    int y = a[x][k];
                    if (c[x] == c[y])
                    {
                        printf("NO\n");
                        return;
                    }
                }
            }
            pair<vector<int>, vector<int> > yv;
            for (int j = 0; j < v.size(); ++j)
            {
                int x = v[j];
                if (c[x] == 1)
                {
                    yv.fi.push_back(x);
                }
                else
                {
                    yv.se.push_back(x);
                }
            }
            vv.push_back(yv);
        }
    }
    dp[0][0] = true;
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (!dp[i][j])
                continue;
            dp[i + 1][j + sz(vv[i].fi)] = true;
            dp[i + 1][j + sz(vv[i].se)] = true;
        }
    }
    if (!dp[vv.size()][n2])
    {
        printf("NO\n");
        return;
    }
    int j = n2;
    for (int i = vv.size(); i >= 1; --i)
    {
        if (dp[i - 1][j - sz(vv[i - 1].fi)])
        {
            for (int k = 0; k < sz(vv[i - 1].fi); ++k)
            {
                ans[vv[i - 1].fi[k]] = 2;
            }
            j -= sz(vv[i - 1].fi);
        }
        else
        {
            for (int k = 0; k < sz(vv[i - 1].se); ++k)
            {
                ans[vv[i - 1].se[k]] = 2;
            }
            j -= sz(vv[i - 1].se);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == 0)
        {
            if (n1)
            {
                --n1;
                ans[i] = 1;
            }
            else
            {
                --n3;
                ans[i] = 3;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d", ans[i]);
    printf("\n");
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