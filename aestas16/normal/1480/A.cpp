/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstring>
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 50;
 
char str[N + 10];
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
signed main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        scanf("%s", str + 1);
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++) {
            if (i % 2) {
                if (str[i] == 'a')
                    str[i] = 'b';
                else
                    str[i] = 'a';
            } else {
                if (str[i] == 'z')
                    str[i] = 'y';
                else
                    str[i] = 'z';
            }
        }
        puts(str + 1);
    }
    return 0;
}