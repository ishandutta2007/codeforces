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
vector<int> g[N];
int l[N], r[N];

int ans;
int u[N];
void dfs(int x)
{
    ll s = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
        s += u[h];
    }

    if (r[x] <= s)
        u[x] = r[x];
    else if (l[x] <= s)
        u[x] = s;
    else
    {
        ++ans;
        u[x] = r[x];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    ans = 0;
    dfs(1);
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}