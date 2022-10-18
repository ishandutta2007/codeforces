/*
     []
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

const int N = 2e2;

int a[N + 10], ans[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int k = fr(), n = fr(), m = fr(), tot = 0;
        for (int i = 1; i <= n + m; i++) fr(a[i]);
        for (int i = 1, j = n + 1; i <= n || j <= n + m;) {
            if (i <= n && j <= n + m) {
                if (a[i] == 0) {
                    ans[++tot] = a[i];
                    k++, i++;
                } else if (a[j] == 0) {
                    ans[++tot] = a[j];
                    k++, j++;
                } else {
                    if (a[i] < a[j]) {
                        ans[++tot] = a[i];
                        if (a[i] > k) {
                            puts("-1");
                            goto cat;
                        }
                        i++;
                    } else {
                        ans[++tot] = a[j];
                        if (a[j] > k) {
                            puts("-1");
                            goto cat;
                        }
                        j++;
                    }
                }
            } else if (i <= n) {
                ans[++tot] = a[i];
                if (a[i] == 0) k++;
                else if (a[i] > k) {
                    puts("-1");
                    goto cat;
                }
                i++;
            } else if (j <= n + m) {
                ans[++tot] = a[j];
                if (a[j] == 0) k++;
                else if (a[j] > k) {
                    puts("-1");
                    goto cat;
                }
                j++;
            }
        }
        for (int i = 1; i <= n + m; i++) printf("%d ", ans[i]);
        puts("");
        cat:;
    }
    return 0;
}