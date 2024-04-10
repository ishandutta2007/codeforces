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

int n, m;
vector<int> a[N], b[N];

bool c[N];

int u[N];

int dp[N];
set<int> s;
void dfs(int x)
{
    s.insert(x);
    dp[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        if (s.find(h) == s.end())
            dfs(h);
        dp[x] = max(dp[x], dp[h] + 1);
    }
}

vector<int> v;
void fi(int x)
{
    v.push_back(x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        if (dp[h] + 1 == dp[x])
        {
            fi(h);
            break;
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        b[i].clear();
        c[i] = false;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        bool z = false;
        for (int i = 0; i < b[x].size(); ++i)
        {
            int h = b[x][i];
            if (c[h])
                continue;
            for (int j = 0; j < b[h].size(); ++j)
            {
                int hh = b[h][j];
                if (c[hh])
                    continue;
                z = true;
            }
        }
        if (z)
            c[x] = true;
    }
    vector<int> ans;
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            ans.push_back(x);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d ", ans[i]);
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}