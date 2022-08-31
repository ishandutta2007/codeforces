#include <bits/stdc++.h>

using namespace std;

main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(abs(a - c), abs(b - d));
}