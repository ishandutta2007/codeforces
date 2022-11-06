#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll n, q, i, x;

ll solve(ll l, ll r, ll x) {
    if (n == 1) return 1;

    ll sz1 = l - 1;
    ll sz2 = r - l + 1;

    if (sz2 >= sz1) {
        if (x <= 2 * sz1) {
            if (x & 1) {
                return - ((x + 1) / 2);
            } else {
                return (x / 2) + r - sz1;
            }
        } else {
            return x - sz1;
        }
    } else {
        ll new_l = l - sz2;
        ll ans = solve(new_l, r, x);
        if (ans < 0) return ans;

        if (new_l % 2 == ans % 2) {
            return - (new_l + ((ans - new_l) / 2));
        } else {
            return l + ((ans - new_l - 1) / 2);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> q;
    for (i = 1; i <= q; i++) {
        cin >> x;
        cout << abs(solve(n, n, x)) << '\n';
    }


    return 0;
}