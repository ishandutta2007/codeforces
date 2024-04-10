#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(100);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    int l = 0, r = 101;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int now = 0;
        for (int i = 0; i < 100; i++) {
            now += a[i] / m;
        }
        if (now < n) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << l;
    return 0;
}