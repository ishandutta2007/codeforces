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

#define maxN 2018

ll p, k, k2, aux, a, b;
vector<ll> coef;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> p >> k;
    k2 = k * k;

    coef = {p % k};
    p /= k;

    while (p > 0) {
        aux = p % k2;
        p /= k2;

        a = aux % k;
        b = aux / k;

        if (a == 0) {
            coef.pb(a);
            coef.pb(b);
            continue;
        }

        a = k - a;
        coef.pb(a);

        if (b + 1 != k) {
            coef.pb(b + 1);
            continue;
        } else {
            coef.pb(0);
            p++;
        }
    }

    while (coef.back() == 0) coef.pop_back();
    cout << coef.size() << '\n';
    for (auto e : coef) cout << e << ' ';

    return 0;
}