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

const int N = 20;

char str[N + 10][N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) str[i][j] = '0';
        for (int i = 1; i <= m; i += 2) str[1][i] = '1';
        if (m % 2) for (int i = 1; i <= m; i += 2) str[n][i] = '1';
        else for (int i = 2; i <= m; i += 2) str[n][i] = '1';
        if (n % 2) for (int i = 3; i < n; i += 2) str[i][1] = str[i][m] = '1';
        else for (int i = 3; i < n - 1; i += 2) str[i][1] = str[i][m] = '1';
        for (int i = 1; i <= n; i++, puts(""))
            for (int j = 1; j <= m; j++) putchar(str[i][j]);
        puts("");
    }
    return 0;
}
/*
10101
00000
10001
00000
10001
10101


1010
0000
1001
0000

101010
000000
100001
000000
010101

101010101
000000000
100000001
000000000
100000001
000000000
100000001
001010100

101010101
000000000
100000001
000000000
100000001
000000000
000000000
010101010
*/