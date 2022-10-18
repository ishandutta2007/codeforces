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
 
char str[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1);
        int n = strlen(str + 1), flag = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (flag == 0 && str[i] == 'a') cnt1++;
            if (flag == 1 && str[i] == 'a') cnt2++;
            if (str[i] != 'a' && flag == 0) flag = 1;
            if (str[i] != 'a' && flag == 1) cnt2 = 0;
        }
        if (flag == 0)
            puts("NO");
        else {
            puts("YES");
            if (cnt1 == cnt2 - 1)
                printf("%sa\n", str + 1);
            else
                printf("a%s\n", str + 1);
        }
    }
    return 0;
}