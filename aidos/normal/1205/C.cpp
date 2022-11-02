#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 2e5 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
int t[55][55];
int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int val;
    cin >> val;
    return val;
}
int A[55][55];
int B[55][55];
int dpa[55][55][55][55];
int dpb[55][55][55][55];
int geta(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || x1 < 1 || x2 > n || x2 < 1) return 0;
    if(y1 > y2 || y1 < 1 || y2 > n || y2 < 1) return 0;

    if(x1 == x2 && y1 == y2) return 1;
    if(A[x1][y1] != A[x2][y2]) return 0;
    int &res = dpa[x1][y1][x2][y2];
    if(res != -1) return res;
    res = 0;
    if(x2 - x1 + y2 - y1 == 1) return res = 1;
    res |= geta(x1 + 1, y1, x2 - 1, y2);
    res |= geta(x1 + 1, y1, x2, y2 - 1);
    res |= geta(x1, y1 + 1, x2 - 1, y2);
    res |= geta(x1, y1 + 1, x2, y2 - 1);
    return res;
}
int getb(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || x1 < 1 || x2 > n || x2 < 1) return 0;
    if(y1 > y2 || y1 < 1 || y2 > n || y2 < 1) return 0;

    if(x1 == x2 && y1 == y2) return 1;
    if(B[x1][y1] != B[x2][y2]) return 0;
    int &res = dpb[x1][y1][x2][y2];
    if(res != -1) return res;
    res = 0;
    if(x2 - x1 + y2 - y1 == 1) return res = 1;
    res |= getb(x1 + 1, y1, x2 - 1, y2);
    res |= getb(x1 + 1, y1, x2, y2 - 1);
    res |= getb(x1, y1 + 1, x2 - 1, y2);
    res |= getb(x1, y1 + 1, x2, y2 - 1);
    return res;
}
void out(int a[55][55]) {
    cout << "!" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
void solve() {
    cin >> n;
    memset(t, -1, sizeof t);
    t[1][1] = 1;
    t[n][n] = 0;
    t[1][2] = 0;
    if(ask(1, 2, 2, 3)) t[2][3] = 0;
    else t[2][3] = 1;
    if(ask(2, 1, 2, 3)) t[2][1] = t[2][3];
    else t[2][1] = 1-t[2][3];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(t[i][j] == -1) {
                if(i > 2) {
                    if(ask(i - 2, j, i, j)) t[i][j] = t[i-2][j];
                    else t[i][j] = 1 - t[i-2][j];
                } else if(j > 2) {
                    if(ask(i, j-2, i, j)) t[i][j] = t[i][j-2];
                    else t[i][j] = 1 - t[i][j-2];
                } else {
                    if(ask(i-1, j-1, i, j)) t[i][j] = t[i-1][j-1];
                    else t[i][j] = 1 - t[i-1][j-1];
                }

            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            A[i][j] = t[i][j];
            B[i][j] = t[i][j];
            if(i % 2 != j % 2) B[i][j] ^= 1;
        }
    }
    memset(dpa, -1, sizeof dpa);
    memset(dpb, -1, sizeof dpb);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int x = i; x <= n; x++) {
                for(int y = j; y <= n; y++) {
                    if(i + j + 2 <= x + y && geta(i, j, x, y) != getb(i, j, x, y)) {
                        
                        if(ask(i, j, x, y) == geta(i, j, x, y)) {
                            out(A);
                        } else {
                            out(B);
                        }
                        return;
                    }
                }
            }
        }
    }
    out(A);
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}