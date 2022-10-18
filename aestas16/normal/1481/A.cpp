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
 
const int N = 1e5;
 
int u, d, l, r;
char str[N + 10];
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
int main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int px = fr(), py = fr();
        int tu = 0, td = 0, tl = 0, tr = 0;
        l = r = u = d = 0;
        if (px > 0) r = px;
        if (px < 0) l = -px;
        if (py > 0) u = py;
        if (py < 0) d = -py;
        scanf("%s", str + 1);
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++)
            if (str[i] == 'R')
                tr++;
            else if (str[i] == 'U')
                tu++;
            else if (str[i] == 'D')
                td++;
            else if (str[i] == 'L')
                tl++;
        if (tr >= r && tu >= u && tl >= l && td >= d)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}