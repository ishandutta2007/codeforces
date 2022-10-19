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
ll k;
int a[N];

ll p[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    ll ans = p[n];
    for (int q = 0; q < n; ++q)
    {
        ll l = 0, r = p[n];
        ll u;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            if (p[n - q] - m + q * (__int128_t)(a[1] - m) <= k)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        ans = min(ans, q + u);
    }

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