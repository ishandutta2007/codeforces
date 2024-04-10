#include <bits/stdc++.h>
using namespace std;

bool fs[21][360], fc[21][360];
int f[10000];
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    f[x] = y;
}
int id(int r, int c) { return r * 360 + c + 1; }

int main(void) {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        memset(fs, 0, sizeof(fs));
        memset(fc, 0, sizeof(fc));
        memset(f, 0, sizeof(f));
        
        for (int i = 1; i < 360; ++i) {
            unite(id(0, i), id(0, 0));
            unite(id(20, i), id(20, 0));
        }

        for (int i = 0; i < n; ++i) {
            char buf[5];
            int a, b, c;
            scanf("%s %d %d %d", buf, &a, &b, &c);
            if (buf[0] == 'S') {
                for (int j = a; j != b; ++j)
                    fs[j][c] = 1;
            } 
            else {
                for (int j = b; j != c; j = (j + 1) % 360)
                    fc[a][j] = 1;
            }
        }

        for (int i = 1; i <= 20; ++i) {
            for (int j = 0; j < 360; ++j) {
                int j_ = (j + 359) % 360;
                int i_ = i - 1;
                if (!fs[i][j])
                    unite(id(i, j_), id(i, j));
                if (!fc[i][j])
                    unite(id(i_, j), id(i, j));
            }
        }

        printf("%s\n", (find(id(0, 0)) == find(id(20, 0))) ? "YES" : "NO");            
    }
    return 0;
}