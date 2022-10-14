#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        bool f = true;
        for (int i = 0; i < a.size(); i++) {
            if (c[i] == b[i] || c[i] == a[i]) {
                continue;
            }
            f = false;
        }
        if (f) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
	return 0;
}