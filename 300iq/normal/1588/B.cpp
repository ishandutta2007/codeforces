#include <bits/stdc++.h>
#define int ll 

using namespace std;

typedef long long ll;

mt19937 rnd(228);
 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    vector <int> a = {2, 1, 5, 4, 3};
    while (t--) {
        int n;
        cin >> n;
        auto ask = [&] (int l, int r) {
            cout << "? " << l + 1 << ' ' << r + 1 << endl;
            ll x;
            cin >> x;
            return x;
        };
        ll ab = ask(0, n - 1);
        int l = -1, r = n-1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (ask(0, m) == ab) {
                r = m;
            } else {
                l = m;
            }
        }
        ll rest = ask(0, r - 1);
        int b = ab - rest + 1;
        ll aa = ab - b * (b - 1) / 2;
        auto get_sqrt = [&] (ll x) {
            ll a = sqrt(x);
            while (a * a < x) a++;
            while (a * a > x) a--;
            return a;
        };
        int a = (int) ((get_sqrt(8 * aa + 1) + 1) / 2);
        int k = r;
        int j = k - b + 1;
        int i = j - a;
        cout << "! " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    }
}