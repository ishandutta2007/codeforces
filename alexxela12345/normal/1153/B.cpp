#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m,h;
    cin >> n >> m >> h;
    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    vector<int> left(n);
    for (int i = 0; i < n; i++) {
        cin >> left[i];
    }
    vector<vector<int>> kek(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> kek[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << min(f[j], left[i]) * kek[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}