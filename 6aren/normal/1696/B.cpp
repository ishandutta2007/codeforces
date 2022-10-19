#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }
        if (*max_element(a.begin(), a.end()) == 0) {
            cout << 0 << '\n';
        } else if (*min_element(a.begin(), a.end()) > 0) {
            cout << 1 << '\n';
        } else {
            int minId = -1, mxId = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) {
                    if (minId == -1) minId = i;
                    mxId = i;
                }
            }
            if (*min_element(a.begin() + minId, a.begin() + mxId + 1) == 0) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}