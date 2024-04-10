#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x=max(x,y)-min(x,y);
        a+=b;
        if (x%a==0) {
            cout << x/a;
        } else {
            cout << -1;
        }
        cout << '\n';
    }
}