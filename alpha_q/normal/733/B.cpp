#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
long long l[N], r[N], L = 0, R = 0;

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", l + i, r + i);
        L += l[i], R += r[i];
    }

    int res = 0;
    long long beauty = abs(L - R);
    for (int i = 1; i <= n; ++i) {
        // swap column i 
        long long nowL = L - l[i] + r[i];
        long long nowR = R - r[i] + l[i];
        long long nowBeauty = abs(nowL - nowR);
        if (nowBeauty > beauty) {
            beauty = nowBeauty;
            res = i;
        }
    }

    printf("%d\n", res);
    return 0;
}