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

ll n, m, k;

void solv()
{
    cin >> n >> m >> k;
    if (n * m * 2 % k != 0)
    {
        cout << "NO" << endl;
        return;
    }

    bool z = false;
    if (k % 2 == 0)
    {
        k /= 2;
        z = true;
    }

    ll x = n / gcd(n, k);
    ll y = m / (k / gcd(n, k));

    if (!z)
    {
        if (x * 2 <= n)
            x *= 2;
        else
            y *= 2;
    }

    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << x << " 0" << endl;
    cout << "0 " << y << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}