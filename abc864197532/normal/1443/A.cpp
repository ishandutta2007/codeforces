#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << (4 * n - i * 2) << ' ';
        }
        cout << '\n';
    }
}