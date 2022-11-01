#include <iostream>

using namespace std;

typedef long long ll;

ll quantity(ll cnt, ll x)
{
    return (cnt - 1) * x / (x - 1) + 1;
}

int main()
{
    ll c1, c2, x, y;
    cin >> c1 >> c2 >> x >> y;
    ll ans = max(quantity(c1, x), quantity(c2, y));
    //cout << (c1 + c2 - 1) * (x * y) / (x * y - 1) << endl;
    ans = max(ans, quantity(c1 + c2, x * y));
    cout << ans;
    return 0;
}