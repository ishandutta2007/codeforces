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
const int N = 1000006;

int n, k;
vector<int> a[N];

pair<int, int> dp[N];

void dfs(int x, int p)
{
    if (a[x].size() == 1)
    {
        dp[x] = m_p(1, 0);
        return;
    }
    vector<int> v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x].fi += dp[h].fi;
        v.push_back(dp[h].se + 1);
    }
    sort(all(v));
    dp[x].se = v[0];
    if (v.size() >= 2)
    {
        if (v[v.size() - 1] + v[v.size() - 2] <= k)
        {
            dp[x].fi -= (v.size() - 1);
            dp[x].se = v.back();
        }
        else
        {
            for (int i = 1; i < v.size(); ++i)
            {
                if (v[i] + v[i - 1] > k)
                {
                    dp[x].fi -= (i - 1);
                    dp[x].se = v[i - 1];
                    break;
                }
            }
        }
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int r;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() > 1)
        {
            r = i;
            break;
        }
    }
    dfs(r, r);
    printf("%d\n", dp[r].fi);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}