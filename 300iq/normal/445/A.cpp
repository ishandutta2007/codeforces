#include <bits/stdc++.h>

using namespace std;

int cnt, n, m;
char c[100][100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == '.') {
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    cout << 'B';
                } else {
                    cout << 'W';
                }
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }
}