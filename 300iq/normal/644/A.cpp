#include <bits/stdc++.h>

using namespace std;

int d[111][111];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cur = 1;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= a; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= b; j++) {
                if (cur <= n) {
                    d[i][j] = cur;
                    cur++;
                }
            }
        } else {
            for (int j = b; j >= 1; j--) {
                if (cur <= n) {
                    d[i][j] = cur;
                    cur++;
                }
            }
        }
    }
    int maximum = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            maximum = max(maximum, d[i][j]);
            bool ev = 0, od = 0;
            for (int t = 0; t < 4; t++) {
                if (i + dx[t] >= 1 && i + dx[t] <= a && j + dy[t] >= 1 && j + dy[t] <= b) {
                    if (d[i + dx[t]][j + dy[t]] == 0) continue;
                    if (d[i + dx[t]][j + dy[t]] % 2 == 0) {
                        ev = 1;
                    } else {
                        od = 1;
                    }
                }
            }
            if (ev && od) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (maximum != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}