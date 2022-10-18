/*
    I will never forget it.
*/

// 392699

#include <cstdio>

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5;

int n, a[N + 10];

int get(int i) {
    printf("? %d\n", i);
    fflush(stdout);
    return fr();
}

int work() {
    if (n == 1) return 1;
    a[1] = get(1), a[2] = get(2);
    if (a[1] < a[2]) return 1;
    a[n] = get(n), a[n - 1] = get(n - 1);
    if (a[n] < a[n - 1]) return n;
    int l = 2, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        a[mid - 1] = get(mid - 1), a[mid] = get(mid), a[mid + 1] = get(mid + 1);
        if (a[mid - 1] < a[mid])
            r = mid - 1;
        else if (a[mid + 1] < a[mid])
            l = mid + 1;
        else
            return mid;
    }
    return l;
}

struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;

signed main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    n = fr();
    printf("! %d\n", work());
    return 0;
}