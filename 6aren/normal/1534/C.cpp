#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int p[N];

int root(int x) {
    return (p[x] == x ? x : p[x] = root(p[x]));
}

bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        p[x] = y;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
        int res = n;
        for (int i = 0; i < n; i++) {
            if (a[0][i] == a[1][i]) {
                res = 0;
                break;
            }
            if (merge(a[0][i], a[1][i])) res--;
        }
        if (res == 0) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1;
        for (int i = 0; i < res; i++) ans = ans * 2 % 1000000007;
        cout << ans << '\n';
    }

    return 0;
}