#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int N;
double a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%lf", a + i);
}

double solve() {
    sort(a, a + N);
    if (a[N - 1] == 1.0) return a[N - 1];
    double s = 0, p = 1;
    for (int i = N - 1; i >= 0 && s <= 1; i--) {
        s += a[i] / (1 - a[i]);
        p *= 1 - a[i];
    }
    return s * p;
}

int main() {
    load();
    printf("%.12lf\n", solve());
    return 0;
}