#include <cstdio>
using namespace std;

const int MAXN = 1005;

int N;
int x[MAXN], y[MAXN];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        scanf("%d%d", x + i, y + i);
    
    int sol = 0;
    for (int i = 0; i < N; i++)
        sol += ccw(x[i], y[i], x[(i + 1) % N], y[(i + 1) % N], x[(i + 2) % N], y[(i + 2) % N]) > 0;
    
    printf("%d\n", sol);
    
    return 0;
}