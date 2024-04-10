#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
        if (a[i] < 0) {
            a[i] *= -1;
            b[i] *= -1;
            c[i] *= -1;
        }
        for (int j = i, k = i - 1; j > 0 && a[j] * b[k] < a[k] * b[j]; --j, --k) {
            std::swap(a[j], a[k]);
            std::swap(b[j], b[k]);
            std::swap(c[j], c[k]);
        }
    }
    double res = 0;
    for (int i = 0; i < n; ++i) {
        double sx = 0, sy = 0;
        for (int j = i, k = 1; k < n; ++k) {
            if (++j == n) j = 0;
            double d = 1.0 / (a[i] * b[j] - a[j] * b[i]);
            double x = (b[j] * c[i] - b[i] * c[j]) * d;
            double y = (a[i] * c[j] - a[j] * c[i]) * d;
            res += x * sy - y * sx;
            sx += x;
            sy += y;
        }
    }
    printf("%.6lf\n", res * 3 / n / (n - 1) / (n - 2));
    return 0;
}