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

int t, ti;
ll x, y, p, q;

ll solve() {
    ll ans;



    if (x != 0 && p == 0) return -1;
    if (x != y && p == q) return -1;
    if (x * q == p * y) return 0;

    ll bonus = 0;
    ll need = (q - (y % q)) % q;

    y += need;
    ans = need;

    ll pp = p * (y / q);
    if (x < pp) x = min(pp, x + need);

    ll dif = pp - x;
    if (dif > 0)
        return ans + q * ((dif + (q - p) - 1) / (q - p));
    else
        return ans + q * ((-dif + p - 1) / p);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> t;
    for (ti = 1; ti <= t; ti++) {
        cin >> x >> y >> p >> q;
        cout << solve() << '\n';
    }



    return 0;
}