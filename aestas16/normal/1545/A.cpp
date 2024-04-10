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

const int N = 1e5;

int a[N + 10], pos[N + 10][2];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        for (int i = 1; i <= n; i++) fr(a[i]), pos[a[i]][0] = pos[a[i]][1] = 0;
        for (int i = 1; i <= n; i++) pos[a[i]][0] += (i % 2), pos[a[i]][1] += (i % 2 == 0);
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            if (i % 2 == 0) {
                pos[a[i]][1]--;
                if (pos[a[i]][1] < 0) {
                    puts("NO");
                    goto cat;
                }
            } else {
                pos[a[i]][0]--;
                if (pos[a[i]][0] < 0) {
                    puts("NO");
                    goto cat;
                }
            }
        puts("YES");
        cat:;
    }
    return 0;
}