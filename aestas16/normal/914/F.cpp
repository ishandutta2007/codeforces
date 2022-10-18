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

const int N = 1e5, ALPHA = 26;

int n, q;
bitset<N + 10> s[ALPHA + 10], ans;
char str[N + 10], S[N + 10];

int h(char ch) { return ch - 'a'; }

struct OI {
    int RP, score;
} FJOI2021;

int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    scanf("%s", str + 1), n = strlen(str + 1);
    for (int i = 1; i <= n; i++) s[h(str[i])][i] = 1;
    for (fr(q); q--;) {
        int opt = fr(), x = fr(), y;
        if (opt == 1)
            scanf("%s", S), s[h(str[x])][x] = 0, s[h(S[0])][x] = 1, str[x] = S[0];
        else {
            fr(y), scanf("%s", S + 1), ans.set();
            int len = strlen(S + 1);
            for (int i = 1; i <= len; i++) ans &= (s[h(S[i])] >> (i - 1));
            int lans = (ans >> x).count(), rans = (ans >> (y - len + 2)).count();
            printf("%d\n", (lans - rans < 0) ? 0 : lans - rans);
        }
    }
    return 0;
}