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
const int N = 3003;

int n;
ll k;
int a[N];

ll p[N];
int p0[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + a[i];

        p0[i] = p0[i - 1];
        if (a[i] == 0)
            ++p0[i];
    }

    ll ans = -1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            int q = p0[j] - p0[i];

            ll l = max(-q * k, -(p0[n] - q) * k - p[n]);
            ll r = min(q * k, (p0[n] - q) * k - p[n]);

            if (l <= r)
            {
                ans = max(ans, p[j] - p[i] + r + 1);
                ans = max(ans, p[i] - p[j] - l + 1);
            }
        }
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}