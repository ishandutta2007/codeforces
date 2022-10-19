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

int n, k, qq;
vector<int> a[N];

int d[N];
int q[N];
void dfs(int x, int p)
{
    q[d[x]]++;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs(h, x);
    }
}

ll p[N];

bool stg(int x)
{
    for (int i = x + 1; i <= n; ++i)
    {
        if (x * 1LL * d[i] - (p[i] - p[i - x]) <= qq)
            return true;
    }
    return false;
}

void solv()
{
    scanf("%d%d%d", &n, &k, &qq);
    for(int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    k = min(k, n - 1);
    dfs(1, 1);
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + d[i];
    int ans = 0;
    int l = 1, r = k;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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