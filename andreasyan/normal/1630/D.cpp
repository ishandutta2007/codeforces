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
const int N = 1000006, INF = 1000000009;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n, m;
int a[N];
int g;

ll solvv()
{
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += abs(a[i]);
    for (int i = 1; i <= g; ++i)
    {
        int q = 0;
        int maxu = -INF;
        int minu = INF;
        for (int j = i; j <= n; j += g)
        {
            if (a[j] < 0)
            {
                maxu = max(maxu, a[j]);
                ++q;
            }
            else
                minu = min(minu, a[j]);
        }

        if (q % 2 == 1)
        {
            ans += 2 * maxu;

            if (-(minu + maxu) > 0)
            {
                ans -= (minu + maxu);
                ans -= (minu + maxu);
            }
        }
    }
    return ans;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    g = 0;
    while (m--)
    {
        int x;
        cin >> x;
        g = gcd(g, x);
    }

    ll ans = solvv();

    for (int i = 1; i <= g; ++i)
        a[i] *= -1;

    ans = max(ans, solvv());
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