#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> degree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        ++degree[x];
        ++degree[y];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            ++ans;
        }
    }
    cout << ans << endl;

}