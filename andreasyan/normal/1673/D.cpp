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
const int M = 1000000007;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

ll b, q, m;
ll c, r, n;

void solv()
{
    cin >> b >> q >> m;
    cin >> c >> r >> n;

    if (r % q != 0)
    {
        cout << "0\n";
        return;
    }

    if (b > c)
    {
        cout << "0\n";
        return;
    }
    if (b + q * (m - 1) < c + r * (n - 1))
    {
        cout << "0\n";
        return;
    }

    if ((c - b) % q != 0)
    {
        cout << "0\n";
        return;
    }

    ll ans = 0;
    for (ll i = 1; i * i <= r; ++i)
    {
        if (r % i == 0)
        {
            ll p = i;
            if (q * p == r * gcd(q, p))
            {
                if (b > c - r)
                {
                    cout << "-1\n";
                    return;
                }
                if (b + q * (m - 1) < c + r * n)
                {
                    cout << "-1\n";
                    return;
                }
                ans = (ans + (r / p) * (r / p)) % M;
            }

            if (r / i != i)
            {
                p = r / i;
                if (q * p == r * gcd(q, p))
                {
                    if (b > c - r)
                    {
                        cout << "-1\n";
                        return;
                    }
                    if (b + q * (m - 1) < c + r * n)
                    {
                        cout << "-1\n";
                        return;
                    }
                    ans = (ans + (r / p) * (r / p)) % M;
                }
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}