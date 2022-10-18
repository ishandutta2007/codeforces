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

const int N = 1e5;

int cnt[N + 10][30];
char str[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        for (int j = 1; j <= m; j++)
            for (int i = 0; i < 26; i++) cnt[j][i] = 0;
        for (int i = 1; i <= n * 2 - 1; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= m; j++) cnt[j][str[j] - 'a']++;
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 0; i < 26; i++)
                if (cnt[j][i] & 1) {
                    putchar(i + 'a');
                    break;
                }
        }
        puts("");
    }
    return 0;
}