#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, x;
        cin >> a >> b >> c >> d >> x;
        int w1 = (a+c-1)/c;
        int w2 = (b+d-1)/d;
        if (w1+w2<=x) {
            cout << w1 << " " << w2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}