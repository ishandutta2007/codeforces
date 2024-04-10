#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll l, r, m;
        cin >> l >> r >> m;
        for (ll a = l; a <= r; a++) {
            ll n = max(1LL, m / a);
            ll p = m - n * a;
            if (p >= l - r && p <= r - l) {
                ll b = 0, c = 0;
                if (p < 0) {
                    c = r;
                    b = r + p;
                } else {
                    b = r;
                    c = r - p;
                }
                cout << a << " " << b << " " << c << "\n";
                break;
            }
            n = (m + a - 1) / a;
            p = m - n * a;
            if (p >= l - r && p <= r - l) {
                ll b = 0, c = 0;
                if (p < 0) {
                    c = r;
                    b = r + p;
                } else {
                    b = r;
                    c = r - p;
                }
                cout << a << " " << b << " " << c << "\n";
                break;
            }
        }
    }
    return 0;
}