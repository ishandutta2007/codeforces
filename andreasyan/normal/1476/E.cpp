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
const int N = 100005;

int n, m, k;
char a[N][5];
char b[N][5];
int u[N];

int t[27 * 27 * 27 * 27];

vector<int> g[N];

int c[N];
bool dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
        {
            if (dfs0(h))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

vector<int> ans;
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs1(h);
    }
    ans.push_back(x);
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i] >> u[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (a[u[i]][j] == '_')
                continue;
            if (a[u[i]][j] != b[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int aa[4] = {};
        for (int j = 0; j < k; ++j)
        {
            if (a[i][j] == '_')
                aa[j] = 26;
            else
                aa[j] = a[i][j] - 'a';
        }
        t[aa[0] + aa[1] * 27 + aa[2] * 27 * 27 + aa[3] * 27 * 27 * 27] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int x = 0; x < (1 << k); ++x)
        {
            int bb[4] = {};
            for (int j = 0; j < k; ++j)
            {
                if ((x & (1 << j)))
                    bb[j] = 26;
                else
                    bb[j] = b[i][j] - 'a';
            }
            int ii = bb[0] + bb[1] * 27 + bb[2] * 27 * 27 + bb[3] * 27 * 27 * 27;
            if (t[ii])
            {
                if (t[ii] != u[i])
                {
                    g[t[ii]].push_back(u[i]);
                }
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (dfs0(x))
        {
            cout << "NO\n";
            return;
        }
    }
    memset(c, 0, sizeof c);
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            dfs1(x);
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}