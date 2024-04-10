/*
 Each time we add a new edge, the shortest path between some x and y can only change if we use the edge a, b

 So for each x, and y, we update the shortest path from x to y as follows
    d[x][y] = min(d[x][y], d[x][a]+c+d[b][y]) represents going from x to a, a to b, b to y
    d[x][y] = min(d[x][y], d[x][b]+c+d[a][y]) represents going from x to b, b to a, a to y
 Then we compute the sum of shortest paths
 */

#include <cstdio>
#include <algorithm> 
using namespace std;
#define MAXN 310
#define int long long
int d[MAXN][MAXN], n, k;
#undef int
int main() {
    #define int long long
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &d[i][j]);
        }
    }

    scanf("%lld", &k);
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        int sum = 0;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                d[x][y] = min(d[x][y], d[x][a]+c+d[b][y]);
                d[x][y] = min(d[x][y], d[x][b]+c+d[a][y]);
                sum += d[x][y];
            }
        }
        printf("%lld ", sum/2);
    }
    printf("\n");
}