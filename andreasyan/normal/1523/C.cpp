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
int a[N];
int p[N];

vector<int> g[N];

vector<int> ans[N];

void dfs(int x)
{
    if (x)
        ans[x].push_back(a[x]);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        ans[h] = ans[x];
        dfs(h);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        ans[i].clear();
    }

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            g[i - 1].push_back(i);
            p[i] = i - 1;
            s.push(i);
        }
        else
        {
            while (a[s.top()] != a[i] - 1)
            {
                s.pop();
            }
            g[p[s.top()]].push_back(i);
            p[i] = p[s.top()];
            s.pop();
            s.push(i);
        }
    }

    dfs(0);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i][0];
        for (int j = 1; j < sz(ans[i]); ++j)
            cout << '.' << ans[i][j];
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
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}