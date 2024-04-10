#include <cstdio>
using namespace std;

const double eps = 1e-12;

int a[5];

double get(double x) {
    return x > eps ? x - eps : x;
}

int main() {
    int S;
    scanf("%d", &S);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    if (!sum) {
        puts("0.000000000000 0.000000000000 0.000000000000");
        return 0;
    }
    double tot = S;
    for (int i = 0; i < 2; i++) {
        double tmp = (double)a[i] * S / sum;
        printf("%.12lf ", get(tmp));
        tot -= tmp;
    }
    printf("%.12lf\n", get(tot));
    return 0;
}