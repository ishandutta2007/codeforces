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
const int N = 1003;

int n;
vector<int> g[N];

vector<int> v;
int p0[N];
void dfs(int x, int p)
{
    p0[x] = p;
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << "? " << n;
    for (int i = 1; i <= n; ++i)
        cout << ' ' << i;
    cout << endl;
    int maxu;
    cin >> maxu;

    dfs(1, 1);

    int l = 1, r = n - 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;

        cout << "? " << m + 1;
        for (int i = 0; i <= m; ++i)
            cout << ' ' << v[i];
        cout << endl;

        int u;
        cin >> u;
        if (u == maxu)
        {
            ans = v[m];
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << "! " << ans << ' ' << p0[ans] << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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