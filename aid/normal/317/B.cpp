#include <iostream>

using namespace std;
const int MAXN = 70;
int b[2 * MAXN + 1][2 * MAXN + 1], c[2 * MAXN + 1][2 * MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    c[MAXN][MAXN] = n;
    while(true) {
        bool change = false;
        for(int i = 0; i < 2 * MAXN + 1; i++)
            for(int j = 0; j < 2 * MAXN + 1; j++)
                if(c[i][j] >= 4) {
                    int p = c[i][j] / 4;
                    b[i][j] -= p * 4;
                    b[i][j + 1] += p;
                    b[i + 1][j] += p;
                    b[i][j - 1] += p;
                    b[i - 1][j] += p;
                    change = true;
                }
        if(!change)
            break;
        for(int i = 0; i < 2 * MAXN + 1; i++)
            for(int j = 0; j < 2 * MAXN + 1; j++) {
                c[i][j] += b[i][j];
                b[i][j] = 0;
            }
    }
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if(x > MAXN || x < -MAXN || y > MAXN || y < -MAXN)
            cout << 0 << '\n';
        else
            cout << c[MAXN + x][MAXN + y] << '\n';
    }
    return 0;
}