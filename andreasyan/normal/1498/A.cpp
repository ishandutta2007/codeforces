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

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

ll gcdsum(ll x)
{
    ll cx = x;
    ll s = 0;
    while (x)
    {
        s += (x % 10);
        x /= 10;
    }
    return gcd(cx, s);
}

void solv()
{
    ll n;
    cin >> n;
    while (1)
    {
        if (gcdsum(n) > 1)
        {
            cout << n << "\n";
            return;
        }
        ++n;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}