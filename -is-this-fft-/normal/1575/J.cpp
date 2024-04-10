    #include <bits/stdc++.h>
    using namespace std;
        
    const int MX = 1e3+1;
     
    int mtx[MX][MX];
     
    void solve() {
        int n, m, k;
        cin >> n >> m >> k;
     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mtx[i][j];
            }
        }
     
        for (int i = 0; i < k; i++) {
            int ball;
            cin >> ball;
     
            int x = 0, y = ball - 1;
     
            while (x != n) {
                if (mtx[x][y] == 2) {
                    x++;
                }
                else if (mtx[x][y] == 1) {
                    mtx[x][y] = 2;
                    y++;
                }
                else if (mtx[x][y] == 3) {
                    mtx[x][y] = 2;
                    y--;
                }
            }
     
            cout << y+1 << ' ';
        }
    }
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
     
        int t = 1;
        // cin >> t;
        while (t--) {
            solve();
        }
    }