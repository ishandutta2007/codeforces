#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += x;
        }
        cout << min(s, m) << endl;
    }
}