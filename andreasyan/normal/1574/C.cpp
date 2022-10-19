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
const ll INF = 2000000009000000009;

int n;
ll a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];

    int qq;
    cin >> qq;
    while (qq--)
    {
        ll x, y;
        cin >> x >> y;

        int l = 1, r = n;
        int u = n + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] >= x)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        ll ans = INF;
        if (u <= n)
        {
            ans = min(ans, max(0LL, y - (s - a[u])));
        }
        --u;
        if (u >= 1)
        {
            ans = min(ans, x - a[u] + max(0LL, y - (s - a[u])));
        }

        cout << ans << "\n";
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
        solv();
    return 0;
}