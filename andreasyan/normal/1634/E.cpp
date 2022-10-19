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

int m;
int n[N];
vector<int> a[N];

int q[N];

vector<int> g[N], gi[N];
pair<int, int> b[N];

vector<char> ans[N];

bool c[N];
void dfs(int x)
{
    while (1)
    {
        if (g[x].empty())
            break;
        int h = g[x].back();
        int hi = gi[x].back();
        g[x].pop_back();
        gi[x].pop_back();

        if (c[abs(hi)])
            continue;
        c[abs(hi)] = true;

        if (hi > 0)
        {
            ans[b[hi].fi][b[hi].se] = 'L';
            ans[b[hi].fi][b[hi].se + 1] = 'R';
        }
        else
        {
            hi *= -1;
            ans[b[hi].fi][b[hi].se] = 'R';
            ans[b[hi].fi][b[hi].se + 1] = 'L';
        }

        dfs(h);
    }
}

void solv()
{
    cin >> m;
    vector<int> v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> n[i];
        for (int j = 0; j < n[i]; ++j)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            v.push_back(x);
        }
    }

    sort(all(v));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            a[i][j] = lower_bound(all(v), a[i][j]) - v.begin() + 1;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
            ++q[a[i][j]];
    }

    for (int x = 1; x <= sz(v); ++x)
    {
        if (q[x] % 2 == 1)
        {
            cout << "NO\n";
            return;
        }
    }

    int z = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n[i]; j += 2)
        {
            g[a[i][j]].push_back(a[i][j + 1]);
            g[a[i][j + 1]].push_back(a[i][j]);
            ++z;
            gi[a[i][j]].push_back(z);
            gi[a[i][j + 1]].push_back(-z);
            b[z] = m_p(i, j);
        }
        ans[i].assign(n[i], 0);
    }

    for (int x = 1; x <= sz(v); ++x)
    {
        dfs(x);
    }

    cout << "YES\n";
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
            cout << ans[i][j];
        cout << "\n";
    }
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