#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a[3];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[(i + j) % 2 + 1].push_back({i, j});
        }
    }
    int done = -1;
    while (done == -1) {
        int col;
        cin >> col;
        if (col == 3) col = 2;
        if (col <= 2) {
            auto foo = a[3 - col].back();
            a[3 - col].pop_back();
            cout << 3 - col << ' ' << foo.first << ' ' << foo.second << endl;
            if (a[3 - col].size() == 0) {
                done = 3 - col;
                break;
            }
        } 
    }
    for (auto foo : a[3 - done]) {
        int col;
        cin >> col;
        int to_col = (col == done ? 3 - col : 6 - done - col);
        cout << to_col << ' ' << foo.first << ' ' << foo.second << endl;
    }

    return 0;
}