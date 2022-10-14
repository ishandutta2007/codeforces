#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb emplace_back()
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    int ai = 0, aj = 0;
    int imin = -1, imax = INF, jmin = -1, jmax = INF;
    bool s = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'B' && s == false) {
                s = true;
                imin = i;
                jmin = j;
            }
            if (jmax == INF && s == true && c == 'B' && j == m - 1) {
                jmax = m - 1;
            }
            if (jmax == INF && s == true && c == 'W') {
                jmax = j - 1;
            }
            if (c == 'B') {
                imax = i;
            }
        }
    }
    cout << (imin + imax) / 2 + 1 << " " << (jmin + jmax) / 2 + 1;
    return 0;
}