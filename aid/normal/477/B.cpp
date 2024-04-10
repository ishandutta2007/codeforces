#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << (2 * (3 * n) - 1) * k << '\n';
    for(int i = 1, j = 0; j < n; i += 6, j++) {
        int a = i, b = i + 2, c = i + 4, d = i + 1;
        if(gcd(d, c) > 1)
            d += 2;
        cout << a * k << ' ' << b * k << ' '
             << c * k << ' ' << d * k << '\n';
    }
    return 0;
}