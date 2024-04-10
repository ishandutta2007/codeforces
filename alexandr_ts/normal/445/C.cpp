#include <cstdio>
#include <algorithm>
using namespace std;
 
int n, m, a, b, c, x[1100];
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)    scanf("%d", &x[i]);
    double ans = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        ans = max(ans, 1.0 * (x[a] + x[b]) / c);
    }
    printf("%.15lf\n", ans);
}