/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
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
        int a = fr(), b = fr(), c = fr(), atot = 0, btot = 0;
        if (c < 2) {
            if (a != b) {
                if (a % b == 0 || b % a == 0) puts("YES");
                else puts("NO");
            } else puts("NO");
            continue;
        }
        while (a % 2 == 0) a >>= 1, atot++;
        while (b % 2 == 0) b >>= 1, btot++;
        for (int i = 3; i * i <= a; i++)
            while (a % i == 0) a /= i, atot++;
        if (a != 1) atot++;
        for (int i = 3; i * i <= b; i++)
            while (b % i == 0) b /= i, btot++;
        if (b != 1) btot++;
        if (atot + btot < c) puts("NO");
        else puts("YES");
    }
    return 0;
}