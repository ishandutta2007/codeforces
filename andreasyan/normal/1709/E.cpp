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

int n;
int a[N];
vector<int> g[N];

int ans;
int pr[N];
set<int> s[N];
void dfs(int x, int p)
{
    if (x == p)
        pr[x] = a[x];
    else
        pr[x] = pr[p] ^ a[x];

    bool z = true;
    s[x].insert(pr[x]);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);

        if (!z)
            continue;

        if (sz(s[x]) < sz(s[h]))
            swap(s[x], s[h]);
        for (auto it = s[h].begin(); it != s[h].end(); ++it)
        {
            if (s[x].find(*it ^ a[x]) != s[x].end())
                z = false;
        }
        for (auto it = s[h].begin(); it != s[h].end(); ++it)
        {
            s[x].insert(*it);
        }
    }
    if (!z)
    {
        s[x].clear();
        ++ans;
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);
    cout << ans << "\n";
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
    {
        solv();
    }
    return 0;
}