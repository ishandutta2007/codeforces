#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 2005;

int N;
int mat[MAXN][MAXN];
ll gl[2 * MAXN], sp[2 * MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            scanf("%d", mat[i] + j);
}

inline ll get(int x, int y) {
    return gl[x + y] + sp[x - y + N] - (ll)mat[x][y];
}

void solve() {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            gl[i + j] += (ll)mat[i][j];
            sp[i - j + N] += (ll)mat[i][j];
        }
    int bx = 0, by = 0, cx = 0, cy = 1;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            if ((i + j) % 2) {
                if (get(i, j) > get(cx, cy)) {
                    cx = i; cy = j;
                }
            }
            else {
                if (get(i, j) > get(bx, by)) {
                    bx = i; by = j;
                }
            }
    cout << get(bx, by) + get(cx, cy) << endl;
    printf("%d %d %d %d\n", ++bx, ++by, ++cx, ++cy);
}

int main() {
    load();
    solve();
    return 0;
}