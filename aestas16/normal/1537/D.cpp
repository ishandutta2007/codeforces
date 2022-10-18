/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

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

const int N = 1e9;

map<int, bool> vis;
// int lst;
// bool f[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int i = 2; i <= N; i *= 4) vis[i] = 1;
    for (int T = fr(); T--;) {
        int n = fr();
        if (n % 2 || vis.count(n)) puts("Bob");
        else puts("Alice");
    }
    // f[1] = 0, f[2] = 0, f[3] = 0, f[4] = 1, lst = 3;
    // for (int i = 5; i <= N; i++) {
    //     for (int j = 2; j * j <= i; j++)
    //         if (i % j == 0 && (f[i - j] == 0 || f[i - i / j] == 0)) {
    //             f[i] = 1;
    //             break;
    //         }
    //     // if (i % 8 == 0 && f[i] == 0) printf("sto i = %d\n", i);
    //     if (i % 2 == 0 && f[i] == 0) printf("i = %lld : %lld, %lld\n", i, f[i], i - lst), lst = i;
    //     else if (i % 2 == 1 && f[i] == 1) printf("orz i = %d\n", i);
    //     // if (f[i] == 0) printf("i = %d : %d\n", i, f[i]);
    // }
    return 0;
}