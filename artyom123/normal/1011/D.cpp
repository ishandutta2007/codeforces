#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    vector <bool> a(n);
    for (int i = 0; i < n; i++) {
        cout << 1 << "\n";
        fflush(stdout);
        int x;
        cin >> x;
        if (x == 0 || x == -2) {
            return 0;
        }
        if (x == 1) {
            a[i] = true;
        }
        else {
            a[i] = false;
        }
    }
    int l = 2, r = m;
    int now = 0;
    while (1) {
        int mid = (r + l) / 2;
        cout << mid << "\n";
        fflush(stdout);
        int x;
        cin >> x;
        if (x == 0) {
            return 0;
        }
        if (a[now] == false) {
            x *= -1;
        }
        now++;
        now %= n;
        if (x == -1) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return 0;
}