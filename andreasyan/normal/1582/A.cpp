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

void solv()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll s = (a + b * 2 + c * 3);

    if (s % 2 == 1)
    {
        cout << "1\n";
        return;
    }

    s /= 2;

    ll t = s;

    ll q = min(c, s / 3);
    c -= q;
    s -= q * 3;

    q = min(c, t / 3);
    c -= q;
    t -= q * 3;

    if (c)
    {
        cout << "1\n";
        return;
    }

    q = min(b, s / 2);
    b -= q;
    s -= q * 2;

    q = min(b, t / 2);
    b -= q;
    t -= q * 2;

    if (b)
    {
        cout << "1\n";
        return;
    }

    cout << "0\n";
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
        solv();
    return 0;
}