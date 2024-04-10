#include <cstdio>

int r[111111], p[111111], a[111111];

int f(int i) {
    int j = p[i];
    if (i == j) return i;
    p[i] = f(j);
    r[i] ^= r[j];
    return p[i];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) p[i] = i;
    for (int k = 0; k < n; ++k) {
        scanf("%d%d", a + k, a + k + 1);
        int x = --a[k] / 2, y = --a[k + 1] / 2, i = f(x), j = f(y);
        r[i] = (r[x] ^ r[y] ^ a[k] ^ a[k + 1] ^ 1) % 2;
        p[i] = j;
    }
    for (int i = 0; i < n; ++i) {
        f(a[i] / 2);
        int j = (r[a[i] / 2] ^ a[i]) % 2;
        printf("%d %d\n", 1 + j, 2 - j);
    }
    return 0;
}