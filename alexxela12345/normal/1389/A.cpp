#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l * 2 <= r) {
            cout << l << " " << 2 * l << endl;
        } else {
            cout << "-1 -1" << endl;
        }
    }
}