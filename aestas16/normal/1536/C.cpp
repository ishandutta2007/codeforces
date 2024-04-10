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

const int N = 5e5;

char str[N + 10];
map<pair<int, int>, int> f;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), x = 0, y = 0;
        scanf("%s", str + 1), f.clear();
        for (int i = 1; i <= n; i++) {
            if (str[i] == 'D') x++;
            else y++;
            f[make_pair(x / gcd(x, y), y / gcd(x, y))]++;
            printf("%d ", f[make_pair(x / gcd(x, y), y / gcd(x, y))]);
        }
        puts("");
    }
    return 0;
}