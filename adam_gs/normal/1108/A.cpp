#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << a << " ";
        if (a==c) {
            cout << c+1;
        } else {
            cout << c;
        }
        cout << '\n';
    }
}