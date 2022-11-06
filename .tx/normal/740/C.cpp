#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int min_len = n;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        min_len = min(min_len, y - x + 1);
    }

    cout << min_len << "\n";
    for (int i = 0; i < n; i++) {
        cout << i % min_len << " ";
    }

    return 0;
}