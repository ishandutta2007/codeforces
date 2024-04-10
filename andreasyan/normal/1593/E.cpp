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
const int N = 400005;

int n, k;
vector<int> g[N];

int q[N];

bool c[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        q[i] = 0;
        c[i] = false;
        g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    set<int> s;
    for (int x = 1; x <= n; ++x)
    {
        q[x] = sz(g[x]);
        if (q[x] <= 1)
            s.insert(x);
    }

    while (k--)
    {
        if (s.empty())
            break;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            int x = *it;
            c[x] = true;
        }
        set<int> ss;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            int x = *it;
            for (int j = 0; j < g[x].size(); ++j)
            {
                int h = g[x][j];
                if (!c[h])
                {
                    --q[h];
                    if (q[h] <= 1)
                        ss.insert(h);
                }
            }
        }
        s = ss;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += (1 - c[i]);

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