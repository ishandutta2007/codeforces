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
const int N = 100005;
const ll INF = 1000000009000000009;

int n;
ll a[N], b[N];
int p[N], k[N];

vector<int> g[N];

void dfs(int x)
{
    a[x] -= b[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
        if (a[h] >= 0)
        {
            a[x] += a[h];
        }
        else
        {
            if (k[h] > (long double)(-INF - a[x]) / a[h])
                a[x] = -INF;
            else
                a[x] += a[h] * k[h];
        }
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    for (int x = 2; x <= n; ++x)
    {
        scanf("%d%d", &p[x], &k[x]);
        g[p[x]].push_back(x);
    }
    dfs(1);
    if (a[1] >= 0)
        printf("YES\n");
    else
        printf("NO\n");
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