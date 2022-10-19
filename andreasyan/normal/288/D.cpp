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
const int N = 80004;

int n;
vector<int> a[N];

ll s[N];
ll q[N];
ll dp[N];

ll ans;

void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
        s[x] += (q[h] * (q[h] - 1)) / 2;
        dp[x] += dp[h];
    }

    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s[x] -= (q[h] * (q[h] - 1)) / 2;
        dp[x] += (q[h] * s[x]);
        s[x] += (q[h] * (q[h] - 1)) / 2;
    }

    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        ans += dp[h] * (q[x] - q[h]);
    }

    ll u = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        u += (q[h] * (q[x] - 1 - q[h]));
    }
    u /= 2;
    u += (q[x] - 1);

    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        u -= (q[h] * (q[x] - 1 - q[h]));
        u -= q[h];
        ans += (q[h] * (q[h] - 1) / 2) * u;
        u += (q[h] * (q[x] - 1 - q[h]));
        u += q[h];
    }
    ans += (((n - q[x]) * (n - q[x] - 1)) / 2) * u;

    dp[x] += s[x];
}

bool dfs0(vector<int>& v, int x, int y, int p)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (dfs0(v, h, y, x))
            return true;
    }
    v.pop_back();
    return false;
}

int not_dfs()
{
    int ans = 0;
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int y1_ = x1 + 1; y1_ <= n; ++y1_)
        {
            for (int x2 = 1; x2 <= n; ++x2)
            {
                for (int y2 = x2 + 1; y2 <= n; ++y2)
                {
                    vector<int> v1, v2;
                    dfs0(v1, x1, y1_, x1);
                    dfs0(v2, x2, y2, x2);
                    sort(all(v1));
                    sort(all(v2));
                    bool z = true;
                    for (int i = 0; i < v1.size(); ++i)
                    {
                        if (binary_search(all(v2), v1[i]))
                        {
                            z = false;
                            break;
                        }
                    }
                    if (z)
                        ++ans;
                }
            }
        }
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    /*n = 50;
    for (int y = 2; y <= n; ++y)
    {
        int x = rnd() % (y - 1) + 1;
        a[x].push_back(y);
        a[y].push_back(x);
        //printf("%d %d\n", x, y);
    }*/
    dfs(1, 1);
    printf("%lld\n", ans);
    //printf("%d\n", not_dfs());
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