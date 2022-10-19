#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        int ans = 1 << __builtin_popcount(a);
        cout << ans << endl;
    }
    return 0;
}