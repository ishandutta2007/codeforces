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

int n;
vector<int> g[N];

int dp[N];
int p0[N];
void dfs(int x, int p)
{
    p0[x] = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x] ^= (dp[h] + 1);
    }
}

bool c[N];
int ans;

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

    dfs(1, 1);

    ans = dp[1];
    c[1] = true;

    if (ans)
        cout << '1';
    else
        cout << '2';

    for (int i = 2; i <= n; ++i)
    {
        int x = i;
        if (!c[x])
        {
            c[x] = true;
            ans ^= dp[x];
            while (1)
            {
                ans ^= (dp[x] + 1);
                ans ^= 1;
                x = p0[x];
                if (c[x])
                    break;
                else
                {
                    c[x] = true;
                    ans ^= dp[x];
                }
            }
        }
        if (ans)
            cout << '1';
        else
            cout << '2';
    }
    cout << '\n';
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