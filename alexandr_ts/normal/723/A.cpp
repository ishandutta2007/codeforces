#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    int d1 = abs(a - b), d2 = abs(a - c), d3 = abs(b - c);
    cout << max(max(d1, d2), d3);
}