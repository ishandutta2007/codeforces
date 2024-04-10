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

const int N = 1e6;

int len, k, fail[N + 10];
char str[N + 10];

void Init() {
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && str[i] != str[j + 1]) j = fail[j];
        if (str[i] == str[j + 1]) j++;
        fail[i] = j;
    }
}

bool chk(int pos) {
    int x = pos / (pos - fail[pos]);
    if (pos % (pos - fail[pos]) == 0) return ((x / k) >= (x % k));
    return ((x / k) > (x % k));
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(len), fr(k), scanf("%s", str + 1), Init();
    for (int i = 1; i <= len; i++) printf("%d", chk(i));
    return puts(""), 0;
}