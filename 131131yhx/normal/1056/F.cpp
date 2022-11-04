#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define M 222

using namespace std;

struct node {
    int a, p;
    node() {}
    node(int _1, int _2) {a = _1, p = _2;}
    bool operator < (const node& X) const {return a < X.a;}
};

int n;

double F[111][1111];

node X[M];

double C, T;

double calc(double x) {
    if(C * x <= 1) return x;
    return (2 * sqrt(C * x) - 1) / C;
}

int solve() {
    scanf("%d", &n);
    scanf("%lf%lf", &C, &T);
    for(int i = 1; i <= n; i++) scanf("%d%d", &X[i].a, &X[i].p);
    sort(X + 1, X + n + 1);
    for(int j = 0; j <= 100; j++)
        for(int i = 0; i <= 1000; i++) F[j][i] = 1e100;
    F[0][0] = 0;
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int a = X[i].a, p = X[i].p;
        for(int j = i - 1; j >= 0; j--)
            for(int k = 0; k <= tot; k++)
                F[j + 1][k + p] = min(F[j + 1][k + p], (F[j][k] + a) * (10. / 9));
        tot += X[i].p;
    }
    for(int i = tot; i >= 0; i--)
        for(int j = 0; j <= 100; j++)
            if(F[j][i] != 1e100 && calc(F[j][i]) + j * 10. <= T) return i;
    return -1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        printf("%d\n", solve());
    }
    return 0;
}