#include <bits/stdc++.h>

using namespace std;

int n, b, p, a, t = 0, c;

int main() {
    cin >> n >> b >> p;
    c = n * p;

    while (n > 1) {
        a = pow(2, floor(log2(n)));
        n %= a; n += a/2;
        t += b * a + a/2;
    }

    cout << t << " " << c << endl;
    return 0;
}