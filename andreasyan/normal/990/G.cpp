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

vector<int> v[N];

int n;
int a[N];
vector<int> g[N];

vector<int> u[N];

ll ans[N];

bool c[N];
vector<int> cv;
int q;
void dfs(int x, int y)
{
    c[x] = true;
    cv.push_back(x);
    ++q;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h] && a[h] % y == 0)
            dfs(h, y);
    }
}

void solv()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            v[j].push_back(i);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        for (int j = 0; j < v[a[i]].size(); ++j)
            u[v[a[i]][j]].push_back(i);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = N - 1; i >= 1; --i)
    {
        cv.clear();
        for (int j = 0; j < u[i].size(); ++j)
        {
            if (!c[u[i][j]])
            {
                q = 0;
                dfs(u[i][j], i);
                ans[i] += (q * 1LL * (q + 1)) / 2;
            }
        }
        for (int j = 0; j < cv.size(); ++j)
            c[cv[j]] = false;
        for (int j = i + i; j < N; j += i)
            ans[i] -= ans[j];
    }
    for (int i = 1; i < N; ++i)
    {
        if (ans[i])
            printf("%d %lld\n", i, ans[i]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}