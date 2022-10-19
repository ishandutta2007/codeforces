#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

int get(int i, int n) {
    if (i == 0) return INF;
    if (i == n + 1) return INF;
    cout << "? " << i << endl;
    int x;
    cin >> x;
    return x;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    int l = 0, r = n + 1;
    while (true) {
        int m = (l + r) / 2;
        int x = get(m, n);
        int lx = get(m - 1, n);
        int rx = get(m + 1, n);
        if (x < lx && x < rx) {
            cout << "! " << m;
            return 0;
        }
        if (x > lx) {
            r = m;
        } else {
            l = m;
        }
    }
    return 0;
}