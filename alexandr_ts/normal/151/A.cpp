#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int v1 = (k * l) / nl;
    int v2 = c * d;
    int v3 = p / np;
    cout << min(v1, min(v2, v3)) / n;
}