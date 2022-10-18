/*
    I will never forget it.
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

const int N = 50;

char mp[N + 10][N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr(), x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", mp[i] + 1);
            for (int j = 1; j <= m; j++)
                if (mp[i][j] != '.') x = i, y = j;
        }
        if (x == y && x == 0) {
            puts("YES");
            for (int i = 1; i <= n; i++, puts("")) {
                for (int j = 1; j <= m; j++) {
                    if ((i + j) % 2) putchar('W');
                    else putchar('R');
                }
            }
            goto cat;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (((i + j) % 2 == (x + y) % 2) && (mp[i][j] != '.') && (mp[i][j] != mp[x][y])) {
                    puts("NO");
                    goto cat;
                } else if (((i + j) % 2 != (x + y) % 2) && (mp[i][j] != '.') && (mp[i][j] == mp[x][y])) {
                    puts("NO");
                    goto cat;
                }
            }
        }
        puts("YES");
        for (int i = 1; i <= n; i++, puts("")) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) % 2 == (x + y) % 2) putchar(mp[x][y]);
                else putchar(mp[x][y] ^ 'W' ^ 'R');
            }
        }
        cat:;
    }
    return 0;
}