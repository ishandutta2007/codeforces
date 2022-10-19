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
int a[N], b[N];

int q[N];
vector<int> g[N];

int c[N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            if (dfs(h))
                return true;
        }
        else if (c[h] == 1)
            return true;
    }
    c[x] = 2;
    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        q[i] = 0;
        g[i].clear();
        c[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        ++q[a[i]];
    int maxx = 1;
    for (int x = 1; x <= n; ++x)
    {
        if (q[x] > q[maxx])
        {
            maxx = x;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == maxx || b[i] == maxx)
            continue;
        g[a[i]].push_back(b[i]);
    }

    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        if (dfs(x))
        {
            cout << "WA\n";
            return;
        }
    }
    cout << "AC\n";
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