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
const int N = 300005, M = 998244353;

int n, m, k;
vector<int> a[N];

bool c[N];
int yl[N];

vector<pair<int, int> > t[N];
map<int, int> mp;
vector<int> v;
bool f;
void dfs(int x, int l)
{
    if (c[x])
    {
        if (l != yl[x])
            f = false;
        return;
    }
    c[x] = true;
    yl[x] = l;
    v.push_back(x);
    for (int i = 0; i < sz(a[x]); ++i)
    {
        if (mp.find(l + i) == mp.end())
            mp[l + i] = a[x][i];
        else if (mp[l + i] != a[x][i])
            f = false;
    }

    for (int i = 0; i < sz(a[x]); ++i)
    {
        while (!t[a[x][i]].empty())
        {
            pair<int, int> h = t[a[x][i]].back();
            t[a[x][i]].pop_back();
            dfs(h.fi, l + i - h.se);
        }
    }
}

int b[N];

int dp[N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (sz(a[i]) == 1)
            continue;
        for (int j = 0; j < sz(a[i]); ++j)
            t[a[i][j]].push_back(m_p(i, j));
    }

    int ak = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (t[i].empty())
            ++ak;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (sz(a[i]) == 1)
            continue;
        if (!c[i])
        {
            mp.clear();
            v.clear();
            f = true;
            dfs(i, 0);

            if (f)
            {
                b[sz(mp)]++;
            }
        }
    }

    vector<int> db;
    for (int i = 1; i <= m; ++i)
    {
        if (b[i])
            db.push_back(i);
    }

    dp[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        dp[i] = (dp[i - 1] * 1LL * ak) % M;
        for (int j = 0; j < sz(db); ++j)
        {
            if (i - db[j] >= 0)
                dp[i] = (dp[i] + dp[i - db[j]] * 1LL * b[db[j]]) % M;
        }
    }

    cout << dp[m] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}