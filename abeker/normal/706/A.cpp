#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a, b, N;
    scanf("%d%d%d", &a, &b, &N);
    double sol = 1e18;
    while (N--) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        sol = min(sol, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
    }
    printf("%.20lf\n", sol);
    return 0;
}