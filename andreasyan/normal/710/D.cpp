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

ll a1, b1, a2, b2, L, R;

void solv()
{
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

    ll minu = min(min(b1, b2), min(L, R)) - 10;
    b1 -= minu;
    b2 -= minu;
    L -= minu;
    R -= minu;

    ll g = gcd(a1, a2);

    if (abs(b2 - b1) % g != 0)
    {
        cout << "0\n";
        return;
    }

    while (1)
    {
        if (b1 > R || b2 > R)
        {
            cout << "0\n";
            return;
        }
        if (b1 == b2)
            break;
        if (b1 > b2)
        {
            swap(b1, b2);
            swap(a1, a2);
        }

        b1 += ((b2 - b1) / a1 + !!((b2 - b1) % a1)) * a1;
    }

    ll d = a1 * a2 / g;

    if (b1 < L)
        b1 += ((L - b1) / d + !!((L - b1) % d)) * d;

    if (b1 > R)
        cout << "0\n";
    else
        cout << (R - b1) / d + 1 << "\n";
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