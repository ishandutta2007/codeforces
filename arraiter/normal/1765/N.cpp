#include <bits/stdc++.h>
using namespace std;

void solve() {
    string x;
    int k;
    cin >> x >> k;
    int n = x.size();
    vector nxt(10, vector<int>(n + 1, -1));
    for (int c = 0; c <= 9; c++) {
        for (int i = n - 1; ~i; i--) {
            if (x[i] == c + '0') nxt[c][i] = i;
            else nxt[c][i] = nxt[c][i + 1];
        }
    }
    int cur = 0;
    for (int i = 0; i < n - k; i++) {
        for (int c = 0; c <= 9; c++) {
            if (!i && !c || !~nxt[c][cur]) continue;
            if (n - nxt[c][cur] >= n - k - i) {
                cout << c;
                cur = nxt[c][cur] + 1;
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}