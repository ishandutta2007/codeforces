#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y, z, n;
    cin >> a >> b >> c >> x >> y >> z >> n;
    if ((a + b + c) / 5 + bool((a + b + c) % 5) + (x + y + z) / 10 + bool((x + y + z) % 10) <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}