#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mn = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        mn = min(mn, r - l + 1);
    }
    cout << mn << '\n';
    for (int i = 0; i < n; i++) cout << i % mn << ' ';
}