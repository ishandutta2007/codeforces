#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int c[maxn], p[maxn];

void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % k == (r + c) % k)
                cout << 'X';
            else
                cout << '.';
        }
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}