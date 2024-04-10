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
const int N = 600005;

int n;
vector<pair<int, int> > g[N];

bool c[N];
vector<int> v;
void dfs(int x)
{
    while (!g[x].empty())
    {
        int h = g[x].back().fi;
        int hi = g[x].back().se;
        g[x].pop_back();
        if (c[hi])
            continue;
        c[hi] = true;
        dfs(h);
        v.push_back(x);
    }
}

int ans[3][N];
char ans1[3][N], ans2[3][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(m_p(y, i * 2 - 1));
        g[y].push_back(m_p(x, i * 2 - 1));

        g[x].push_back(m_p(y, i * 2));
        g[y].push_back(m_p(x, i * 2));
    }

    int k = 0;
    for (int x = 1; x <= n * 2; ++x)
    {
        v.clear();
        dfs(x);
        if (v.empty())
            continue;
        if (sz(v) == 2)
        {
            cout << "-1\n";
            return;
        }

        int i = 0;
        for (int j = k + 1; j <= k + sz(v) / 2; ++j)
            ans[1][j] = v[i++];
        for (int j = k + sz(v) / 2; j >= k + 1; --j)
            ans[2][j] = v[i++];

        if ((sz(v) / 2) % 2 == 0)
        {
            for (int j = k + 1; j <= k + sz(v) / 2; j += 2)
            {
                ans1[1][j] = 'L';
                ans1[1][j + 1] = 'R';

                ans1[2][j] = 'L';
                ans1[2][j + 1] = 'R';
            }

            ans2[1][k + 1] = 'U';
            ans2[2][k + 1] = 'D';

            ans2[1][k + sz(v) / 2] = 'U';
            ans2[2][k + sz(v) / 2] = 'D';

            for (int j = k + 2; j <= k + sz(v) / 2 - 1; j += 2)
            {
                ans2[1][j] = 'L';
                ans2[1][j + 1] = 'R';

                ans2[2][j] = 'L';
                ans2[2][j + 1] = 'R';
            }
        }
        else
        {
            for (int j = k + 1; j <= k + sz(v) / 2 - 1; j += 2)
            {
                ans1[1][j] = 'L';
                ans1[1][j + 1] = 'R';

                ans1[2][j] = 'L';
                ans1[2][j + 1] = 'R';
            }

            ans1[1][k + sz(v) / 2] = 'U';
            ans1[2][k + sz(v) / 2] = 'D';

            ans2[1][k + 1] = 'U';
            ans2[2][k + 1] = 'D';

            for (int j = k + 2; j <= k + sz(v) / 2; j += 2)
            {
                ans2[1][j] = 'L';
                ans2[1][j + 1] = 'R';

                ans2[2][j] = 'L';
                ans2[2][j + 1] = 'R';
            }
        }

        k += sz(v) / 2;
    }

    cout << "2 " << n << "\n\n";

    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << ans[i][j] << ' ';
        cout << "\n";
    }
    cout << "\n";

    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << ans1[i][j];
        cout << "\n";
    }
    cout << "\n";

    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << ans2[i][j];
        cout << "\n";
    }
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}