#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

int mat[5];
ld bound[5][5];

void load() {
    for (int i = 0; i < 4; i++)
        scanf("%d", mat + i);
}

bool check(ld val) {
    for (int i = 0; i < 4; i++) {
        bound[i][0] = mat[i] - val;
        bound[i][1] = mat[i] + val;
    }
    ld lo1 = 1e18, hi1 = -1e18;
    ld lo2 = 1e18, hi2 = -1e18;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            lo1 = min(lo1, bound[0][i] * bound[3][j]);
            hi1 = max(hi1, bound[0][i] * bound[3][j]);
            lo2 = min(lo2, bound[1][i] * bound[2][j]);
            hi2 = max(hi2, bound[1][i] * bound[2][j]);
        }
    return hi1 >= lo2 && hi2 >= lo1;
}

ld solve() {
    ld lo = 0, hi = 1e18;
    for (int i = 0; i < 1000; i++) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    load();
    printf("%.10lf\n", (double)solve());
    return 0;
}