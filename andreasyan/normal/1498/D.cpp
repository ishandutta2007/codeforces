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
const int N = 202, M = 100005;

int n, m;

bool c[M];
int q[M];
int ans[M];

void solv()
{
    cin >> n >> m;
    c[0] = true;
    for (int i = 1; i <= m; ++i)
        ans[i] = -1;
    for (int i = 1; i <= n; ++i)
    {
        int ty, y;
        ll x;
        cin >> ty >> x >> y;
        for (int j = 0; j <= m; ++j)
        {
            if (c[j])
                q[j] = y;
        }
        for (int j = 0; j <= m; ++j)
        {
            if (c[j])
            {
                if (q[j])
                {
                    if (ty == 1)
                    {
                        ll u = j * 100000LL + x;
                        if (u / 100000 + !!(u % 100000) <= m)
                        {
                            c[u / 100000 + !!(u % 100000)] = true;
                            q[u / 100000 + !!(u % 100000)] = max(q[u / 100000 + !!(u % 100000)],
                                                                 q[j] - 1);
                        }
                    }
                    else
                    {
                        ll u = j * x;
                        if (u / 100000 + !!(u % 100000) <= m)
                        {
                            c[u / 100000 + !!(u % 100000)] = true;
                            q[u / 100000 + !!(u % 100000)] = max(q[u / 100000 + !!(u % 100000)],
                                                                 q[j] - 1);
                        }
                    }
                }
            }
        }
        for (int j = 1; j <= m; ++j)
        {
            if (c[j])
            {
                if (ans[j] == -1)
                    ans[j] = i;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}