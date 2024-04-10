#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;
#define ll long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int a2 = a % 2, b2 = b % 2, c2 = c % 2, d2 = d % 2;
        if (a2 + b2 + c2 + d2 <= 1) {
            cout << "Yes\n";
            continue;
        }
        if (min({a, b, c}) > 0 && a2 + b2 + c2 + d2 >= 3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}