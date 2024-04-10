#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int q = a / gcd(a, b), p = b / gcd(a, b);
    for(int i = 1; i < a; i++)
        for(int j = -a + 1; j < 0; j++)
            if(i * i + j * j == a * a && !(i % q) && !(j % q)) {
                int x = (i / q) * p, y = (-j / q) * p;
                if(y == i)
                    continue;
                cout << "YES\n" << 0 << ' ' << 0 << '\n'
                     << j << ' ' << i << '\n'
                     << x << ' ' << y << '\n';
                return 0;
            }
    cout << "NO\n";
    return 0;
}