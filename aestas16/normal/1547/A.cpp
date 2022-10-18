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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int xa = fr(), ya = fr(), xb = fr(), yb = fr(), xf = fr(), yf = fr();
        int ans = abs(xa - xb) + abs(ya - yb);
        if (xa == xb && xf == xa && ((ya <= yf && yf <= yb) || (ya >= yf && yf >= yb))) ans += 2;
        else if (ya == yb && yf == ya && ((xa <= xf && xf <= xb) || (xa >= xf && xf >= xb))) ans += 2;
        printf("%d\n", ans);
    }
    return 0;
}