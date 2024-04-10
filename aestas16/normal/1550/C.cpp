/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), ans = n + n - 1;
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n - 2; i++)
            if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
                continue;
            else if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
                continue;
            else
                ans++;
        for (int i = 1; i <= n - 3; i++)
            if ((a[i] < a[i + 1] && a[i] > a[i + 2] && a[i + 2] < a[i + 3] && a[i + 1] > a[i + 3]) ||
                (a[i] > a[i + 1] && a[i] < a[i + 2] && a[i + 3] > a[i + 1] && a[i + 3] < a[i + 2])) ans++;
        // if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2] && a[i + 2] >= a[i + 3]) continue;
        // else if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2] && a[i + 2] <= a[i + 3]) continue;
        // else ans++;
        printf("%d\n", ans);
    }
    return 0;
}