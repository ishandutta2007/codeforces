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

const int N = 2e3;

int cnt[5];
char str[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), a = fr(), b = fr();
        cnt[0] = cnt[1] = 0;
        scanf("%s", str + 1);
        if (b > 0) printf("%d\n", (a + b) * n);
        else {
            cnt[str[1] - '0']++;
            for (int i = 2; i <= n + 1; i++) {
                if (str[i] != str[i - 1]) cnt[str[i - 1] - '0']++;
            }
            printf("%d\n", a * n + max((cnt[0] + 1) * b, (cnt[1] + 1) * b));
        }
        // for (int i = 1; i <= n; i++) 
    }
    return 0;
}