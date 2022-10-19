#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i); 
}

double aps(double x) {
    return x > 0 ? x : -x;
}

double calc(double x) {
    double mini = 0, maks = 0;
    double sum = 0, res = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] - x;
        res = max(res, aps(sum - mini));
        res = max(res, aps(sum - maks));
        mini = min(mini, sum);
        maks = max(maks, sum);
    }
    return res;
}

double solve() {
    double lo = *min_element(a, a + N);
    double hi = *max_element(a, a + N);
    for (int i = 0; i < 200; i++) {
        double l = lo + (hi - lo) / 3;
        double r = hi - (hi - lo) / 3;
        if (calc(l) < calc(r)) hi = r;
        else lo = l;
    }
    return calc(lo);
}

int main() {
    load();
    printf("%.12lf\n", solve());
    return 0;
}