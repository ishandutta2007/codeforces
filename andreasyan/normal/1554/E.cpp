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
const int N = 100005, M = 998244353;

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

int n;
vector<int> g[N];

int q[N];
bool dfs(int x, int p, int k)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        ++q[x];
        if (!dfs(h, x, k))
            return false;
    }
    if (q[x] % k == 0)
        return true;
    if ((q[x] + 1) % k == 0 && x != p)
    {
        --q[p];
        ++q[x];
        return true;
    }
    return false;
}

int stg(int k)
{
    if (k > 1)
    {
        for (int x = 1; x <= n; ++x)
            q[x] = 0;
        if (dfs(1, 1, k))
            return true;
        return false;
    }
    int ans = 1;
    for (int i = 0; i < n - 1; ++i)
        ans = (ans * 2LL) % M;
    return ans;
}

int ans[N];

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = n; i >= 1; --i)
    {
        if ((n - 1) % i != 0)
        {
            ans[i] = 0;
            continue;
        }
        ans[i] = stg(i);
        for (int j = i + i; j <= n; j += i)
            ans[i] = (ans[i] - ans[j] + M) % M;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}