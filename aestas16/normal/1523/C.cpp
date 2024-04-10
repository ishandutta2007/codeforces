/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e3;

int n, tot, a[N + 10], cnt[N + 10];
string ans[N + 10];

void print() {
    printf("%d", cnt[1]);
    for (int i = 2; i <= tot; i++)
        printf(".%d", cnt[i]);
    puts("");
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        n = fr(), tot = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            fr(a[i]);
            if (a[i] == 1) cnt[++tot] = 1, print();
            else {
                for (int j = tot; j; j--)
                    if (a[i] == cnt[j] + 1) {
                        cnt[j]++, tot = j;
                        print();
                        break;
                    }
            }
        }
    }
    return 0;
}