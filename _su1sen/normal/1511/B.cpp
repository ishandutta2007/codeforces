#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int c) {
    int x = 1;
    for (int i = 2; i <= c; i++) {
        x *= 10;
    }
    int v = x, w = x;
    for (int i = 0; i < a - c; i++) {
        v *= 10;
    }
    for (int i = 0; i < b - c; i++) {
        w *= 10;
    }
    while (__gcd(v, w) != x) {
        v += x;
    }
    cout << v << ' ' << w << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    return 0;
}