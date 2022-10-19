#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, M, X, Y, Z, P;
    scanf("%d%d%d%d%d%d", &N, &M, &X, &Y, &Z, &P);
    X %= 4;
    Y %= 2;
    Z %= 4;
    int n = N, m = M;
    while (P--) {
        int x, y;
        scanf("%d%d", &x, &y);
        N = n, M = m;
        for (int i = 0; i < X; i++) {
            int nx = y;
            int ny = N - x + 1;
            x = nx;
            y = ny;
            swap(N, M);
        }
        for (int i = 0; i < Y; i++) 
            y = M + 1 - y;
        for (int i = 0; i < Z; i++)  {
            int nx = M - y + 1;
            int ny = x;
            x = nx;
            y = ny;
            swap(N, M);
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}