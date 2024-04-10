#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n, h;

int main() {
    cin >> n >> h;
    ld h0 = h * sqrt((ld)1 / (ld)n);
    cout.precision(10);
    cout << fixed << h0 << '\n';
    for(int i = 1; i < n - 1; i++) {
        h0 *= sqrt((ld)1 + (ld)1 / (ld)i);
        cout << fixed << h0 << '\n';
    }
}