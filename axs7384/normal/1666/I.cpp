#include <bits/stdc++.h>
using namespace std;

int scan(int r, int c) {
    printf("SCAN %d %d\n", r, c);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

int dig(int r, int c) {
    printf("DIG %d %d\n", r, c);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    int A = scan(1, 1);
    A += 4;
    int B = scan(1, m);
    B = B + 2 - 2 * m;
    int C = (A + B) / 2;
    int D = (A - B) / 2;
    int r1, c1, r2, c2;
    int X = scan(C / 2, 1);
    X = X - (D - 2);
    r1 = C / 2 - X / 2;
    r2 = C / 2 + X / 2 + (C & 1);
    int Y = scan(1, D / 2);
    Y = Y - (C - 2);
    c1 = D / 2 - Y / 2;
    c2 = D / 2 + Y / 2 + (D & 1);

    int Z1, Z2;
    if (Z1 = dig(r1, c1)) {
        Z2 = dig(r2, c2);
    }
    else {
        Z1 = dig(r1, c2);
        Z2 = dig(r2, c1);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}