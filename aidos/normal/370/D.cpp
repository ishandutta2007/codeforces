#include <bits/stdc++.h>
using namespace std;
char c[2020][2020];
int sum[2020][2020];
int n, m;
set<int> sx, sy;
int get_sum(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == 'w') {
                sx.insert(i);
                sy.insert(j);
            }
        }
    }
    int ax = *sx.begin();
    int bx = *sx.rbegin();
    int ay = *sy.begin();
    int by = *sy.rbegin();
    int len = max(bx-ax, by-ay);

    int x1 = -1, y1 = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (c[i-1][j-1] == 'w');
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + len >= n || j + len >= m) continue;
            if(ax < i || ax > i + len || bx < i || bx > i + len) continue;
            if(ay < j || ay > j + len || by < j || by > j + len) continue;

            if(get_sum(i+2, j + 2, i + len, j + len) == 0) {
                x1 = i;
                y1 = j;
            }
        }
    }
    if(x1 == -1) {
        cout << -1 << "\n";
        return 0;
    }
    int x2 = x1 + len, y2 = y1 + len;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(i == x1 || j == y1 || i == x2 || j == y2) {
                if(c[i][j]=='.') c[i][j] = '+';
            }
        }
    }
    for(int  i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}