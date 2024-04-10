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
const int N = 6003;

int n;
pair<int, int> a[N];

int z;
vector<int> v;
map<int, int> mp;

bool c[N][N];

int dp[N][N];

vector<int> ur[N], ul[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].fi, &a[i].se);

    z = 0;
    v.clear();
    mp.clear();
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].fi);
        v.push_back(a[i].se);
    }
    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
        }
    }
    for (int i = 1; i <= z; ++i)
    {
        ul[i].clear();
        ur[i].clear();
        for (int j = i; j <= z; ++j)
        {
            c[i][j] = false;
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].fi = mp[a[i].fi];
        a[i].se = mp[a[i].se];
        c[a[i].fi][a[i].se] = true;
        ur[a[i].fi].push_back(a[i].se);
        ul[a[i].se].push_back(a[i].fi);
    }
    for (int i = 1; i <= z; ++i)
    {
        sort(all(ul[i]));
        reverse(all(ul[i]));
        sort(all(ur[i]));
    }

    for (int d = 1; d <= z; ++d)
    {
        for (int l = 1; l <= z - d + 1; ++l)
        {
            int r = l + d - 1;
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            for (int i = 0; i < ur[l].size(); ++i)
            {
                int m = ur[l][i];
                if (m >= r)
                    break;
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            for (int i = 0; i < ul[r].size(); ++i)
            {
                int m = ul[r][i];
                if (m <= l)
                    break;
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            dp[l][r] += c[l][r];
        }
    }
    printf("%d\n", dp[1][z]);
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