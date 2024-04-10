#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll x;
    cin >> x;
    ll a, now = LLONG_MAX;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i != 0) continue;
        if (now > x / i and __gcd(i, x / i) == 1) a = i, now = x / i;
    }
    cout << a << ' ' << x / a << endl;
}