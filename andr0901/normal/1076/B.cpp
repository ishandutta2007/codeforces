#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    bool f = 1;
    if (n % 2) {
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n -= i;
                f = 0;
                break;
            }
        }
        if (f) {
            cout << 1;
            return 0;
        }
    }
    cout << n / 2 + !f;
    return 0;
}