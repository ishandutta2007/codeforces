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
 
const int N = 3e5;
 
char s1[N + 10], s2[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), cnt0 = 0, cnt1 = 0, cnt00 = 0, cnt11 = 0;
        scanf("%s%s", s1 + 1, s2 + 1);
        for (int i = 1; i <= n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == '0')
                    cnt0++;
                else
                    cnt1++;
                if (cnt00 != cnt11) {
                    puts("NO");
                    goto cat;
                } else
                    cnt00 = cnt11 = 0;
            } else {
                if (s1[i] == '0')
                    cnt00++;
                else
                    cnt11++;
                if (cnt0 != cnt1) {
                    puts("NO");
                    goto cat;
                } else
                    cnt0 = cnt1 = 0;
            }
        }
        if (cnt0 == cnt1)
            puts("YES");
        else
            puts("NO");
    cat:;
    }
    return 0;
}