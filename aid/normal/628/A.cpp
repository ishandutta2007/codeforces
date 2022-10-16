#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b, p;
    cin >> n >> b >> p;
    int x = 0, y = n * p;
    while(n > 1) {
        int k = 1;
        while(2 * k <= n)
            k *= 2;
        x += (k / 2) * (2 * b + 1);
        n -= k / 2;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}