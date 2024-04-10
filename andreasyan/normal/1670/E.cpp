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
const int N = (1 << 18);

int n;
vector<int> g[N], gi[N];

int ans1[N], ans2[N];

int z;
void dfs(int x, int p, int u)
{
    if (x == p)
    {
        ans1[x] = n;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (h == p)
            continue;
        ++z;
        ans2[hi] = (u | z);
        ans1[h] = ((u ^ n) | z);
        dfs(h, x, (u ^ n));
    }
}

void solv()
{
    cin >> n;
    n = (1 << n);

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        gi[i].clear();
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    z = 0;
    dfs(1, 1, n);

    cout << "1\n";
    for (int i = 1; i <= n; ++i)
        cout << ans1[i] << ' ';
    cout << "\n";
    for (int i = 1; i <= n - 1; ++i)
        cout << ans2[i] << ' ';
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