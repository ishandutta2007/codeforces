#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n>2) {
            cout << 2*m << '\n';
        } else if (n>1) {
            cout << m << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}