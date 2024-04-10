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
const int N = 100005, S = 512, M = 998244353;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, m;
vector<int> g[N];

bool c[N];
int u[N];
bool cc[N];
void dfs(int x)
{
    if (c[x])
        return;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }

    for (int i = 0; i <= sz(g[x]); ++i)
        cc[i] = false;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        cc[u[h]] = true;
    }
    for (int i = 0; ; ++i)
    {
        if (!cc[i])
        {
            u[x] = i;
            break;
        }
    }
}

int q[S];

int a[S + 5][S + 5];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int x = 1; x <= n; ++x)
        dfs(x);
    for (int x = 1; x <= n; ++x)
        q[u[x]]++;

    int rn = ast(n + 1, M - 2);
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            a[i][j] = (q[(i ^ j)] * 1LL * rn) % M;
        }
        a[i][i] = (a[i][i] - 1 + M) % M;
        if (i == 0)
            a[i][S] = 0;
        else
            a[i][S] = (-rn + M) % M;
    }

    for (int i = 0; i < S; ++i)
    {
        /*for (int j = i; j < S; ++j)
        {
            if (a[j][i] != 0)
            {
                for (int k = 0; k <= S; ++k)
                {
                    swap(a[i][k], a[j][k]);
                }
                break;
            }
        }*/
        for (int j = 0; j < S; ++j)
        {
            if (i == j)
                continue;
            int z = (a[j][i] * 1LL * ast(a[i][i], M - 2)) % M;
            for (int k = i; k <= S; ++k)
            {
                a[j][k] = (a[j][k] - (z * 1LL * a[i][k]) % M + M) % M;
            }
        }
    }

    int ans = (a[0][S] * 1LL * ast(a[0][0], M - 2)) % M;
    printf("%d\n", ans);
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