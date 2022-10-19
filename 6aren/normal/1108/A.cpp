#include <bits/stdc++.h>

using namespace std;

int ntest, a, b, c, d;

int main() {
    cin >> ntest;

    while (ntest--) {
        cin >> a >> b >> c >> d;
        if (a != c) cout << a << " " << c << endl;
        else if (b != a) cout << b << " " << c << endl;
        else if (d != c) cout << a << " " << d << endl;
    }
    //cin >> ntest;
    return 0;
}