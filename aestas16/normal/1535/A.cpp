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

int a[10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(a[1]), fr(a[2]), fr(a[3]), fr(a[4]);
        int a1 = max(a[1], a[2]), a2 = max(a[3], a[4]);
        sort(a + 1, a + 5);
        if (a1 == a[3] && a2 == a[4]) puts("YES");
        else if (a1 == a[4] && a2 == a[3]) puts("YES");
        else puts("NO");
    }
    return 0;
}