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
const int N = 300005;

int n, m;
vector<int> g[N];

bool c[N];

queue<int> q;

vector<int> ans;
void ave(int x)
{
    ans.push_back(x);
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            c[h] = true;
            q.push(h);
        }
    }
}

void solv()
{
    cin >> n >> m;

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        c[x] = false;
    }
    ans.clear();

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ave(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
                ave(h);
        }
    }

    bool z = true;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            z = false;
            break;
        }
    }

    if (!z)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i] << ' ';
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
    {
        solv();
    }
    return 0;
}