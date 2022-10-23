#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> top(50, n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
        if (top[c[i]] == n) {
            top[c[i]] = i;
        }
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        --t;
        int p = top[t];
        cout << p + 1 << " \n"[i == q - 1];
        for (int x = 0; x < 50; ++x) {
            if (top[x] < p) {
                ++top[x];
            }
        }
        top[t] = 0;
    }
    return 0;
}