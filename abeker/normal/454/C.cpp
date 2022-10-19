#include <cstdio>
using namespace std;

typedef long double ld;

int N, M;

void load() {
    scanf("%d%d", &M, &N);
}

ld pow(ld x, int y) {
    if (!y) return 1.0;
    if (y & 1) return pow(x, y - 1) * x;
    ld res = pow(x, y >> 1);
    return res * res;
}

ld solve() {
    ld sol = 0.0;
    for (int k = 1; k <= M; k++) 
        sol += (ld)k * (pow((ld)k / M, N) - pow((ld)(k - 1) / M, N));
    return sol;
}

int main() {
    load();
    printf("%.12lf\n", (double)solve());
    return 0;
}