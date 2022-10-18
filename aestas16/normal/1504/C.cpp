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

const int N = 2e5;

char str[N + 10], ans1[N + 10], ans2[N + 10];

struct OI {
    int RP, score;
} FJOI2021;

int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), top1 = 0, top2 = 0, cnt0 = 0, cnt1 = 0, qwq = 0;
        memset(ans1, 0, sizeof(ans1)), memset(ans2, 0, sizeof(ans2));
        scanf("%s", str + 1);
        for (int i = 1; i <= n; i++)
            if (str[i] == '0')
                cnt0++;
            else
                cnt1++;
        if (cnt0 % 2 == 1) {
            puts("NO");
            goto cat;
        }
        if (str[1] == '0' || str[n] == '0') {
            puts("NO");
            goto cat;
        }
        for (int i = 1; i <= n; i++) {
            if (str[i] == '0') {
                if (top1 < top2)
                    ans1[i] = '(', ans2[i] = ')', top1++, top2--;
                else
                    ans1[i] = ')', ans2[i] = '(', top1--, top2++;
            } else {
                if (qwq < cnt1 / 2)
                    ans1[i] = ans2[i] = '(', top1++, top2++, qwq++;
                else
                    ans1[i] = ans2[i] = ')', top1--, top2--;
            }
            if (top1 < 0 || top2 < 0) {
                puts("NO");
                goto cat;
            }
        }
        puts("YES"), puts(ans1 + 1), puts(ans2 + 1);
    cat:;
    }
    return 0;
}
/*
11011100000111
(()((()()())))
((((((()()()))
*/
/*

*/