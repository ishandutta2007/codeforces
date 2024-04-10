/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e2;

bool vis[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        if (n & 1) {
            printf("3 1 2 ");
            for (int i = 4; i <= n; i++) {
                if (i & 1) printf("%d ", i - 1);
                else printf("%d ", i + 1);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i & 1) printf("%d ", i + 1);
                else printf("%d ", i - 1);
            }
        }
        puts("");
    }
    return 0;
}