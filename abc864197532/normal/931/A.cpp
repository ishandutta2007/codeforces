#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int n = abs(a - b);
    int mid = n >> 1, mid2 = n - mid;
    cout << mid * (mid + 1) / 2 + mid2 * (mid2 + 1) / 2;
}