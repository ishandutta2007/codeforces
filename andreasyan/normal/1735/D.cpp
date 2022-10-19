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
const int N = 1003, K = 22;

int n, k;
int a[N][K];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
            cin >> a[i][j];
    }

    map<ll, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            ll x = 0;
            for (int t = 1; t <= k; ++t)
            {
                if (a[i][t] == a[j][t])
                    x = (x * 3 + a[i][t]);
                else
                    x = (x * 3 + 3 - a[i][t] - a[j][t]);
            }
            mp[x]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll x = 0;
        for (int j = 1; j <= k; ++j)
            x = (x * 3 + a[i][j]);
        ans += (mp[x] * (mp[x] - 1)) / 2;
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