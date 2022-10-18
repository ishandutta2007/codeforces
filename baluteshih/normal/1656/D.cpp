#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

bool check(ll n, ll k) {
    ll rm = k / 2 * (k - 1);
    if (n < rm) return 0;
    return (n - rm) % k == 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll pw = 2;
        while (n % 2 == 0)
            pw <<= 1, n >>= 1;
        if (n >= pw + 1)
            cout << pw << "\n";
        else if (n > 1)
            cout << n << "\n";
        else
            cout << "-1\n";
    }
}