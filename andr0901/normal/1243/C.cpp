#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1)
        return cout << 1, 0;
    vector <ll> divisors;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.pb(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        divisors.pb(n);
    if (divisors.size() > 1)
        cout << 1;
    else
        cout << divisors[0];
    return 0;
}