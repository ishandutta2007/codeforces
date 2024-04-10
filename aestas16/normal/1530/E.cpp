/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

#define putchar(c) (_P == _Q && (fwrite(_O, 1, 1 << 23, stdout), _P = _O), *_P++ = c)

char _O[1 << 23], *_P = _O, *_Q = _O + (1 << 23);

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, ALPHA = 26;

char str[N + 10];
int cnt[ALPHA + 10];

void print(int n) {
    for (int i = 1; i <= n; i++) putchar(str[i]);
    putchar('\n');
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1);
        for (int i = 0; i < ALPHA; i++) cnt[i] = 0;
        int tot = 0, n = strlen(str + 1);
        for (int i = 1; i <= n; i++)
            cnt[str[i] - 'a']++, tot += (cnt[str[i] - 'a'] == 1);
        if (tot == 1) {
            print(n);
            continue;
        }
        sort(str + 1, str + n + 1);
        for (int i = 0; i < ALPHA; i++)
            if (cnt[i] == 1) {
                for (int j = 1; j <= n; j++) if (str[j] == 'a' + i) str[j] = 0;
                sort(str + 1, str + n + 1), str[1] = 'a' + i, print(n);
                goto cat;
            }
        for (int i = 0; i < ALPHA; i++)
            if (cnt[i]) {
                if (cnt[i] - 2 <= n - cnt[i]) {
                    for (int j = 1; j <= n; j++) if (str[j] == 'a' + i) str[j] = 'z' + 1;
                    sort(str + 1, str + n + 1), putchar('a' + i), cnt[i]--;
                    for (int j = 1; str[j] != 'z' + 1; j++) {
                        if (cnt[i] > 0) putchar('a' + i), cnt[i]--;
                        putchar(str[j]);
                    }
                    if (cnt[i] > 0) putchar('a' + i), cnt[i]--;
                    putchar('\n');
                    goto cat;
                }
                int pos1 = i + 1, pos2;
                while (!cnt[pos1]) pos1++;
                if (tot == 2) {
                    putchar('a' + i);
                    for (int j = 1; j <= cnt[pos1]; j++) putchar('a' + pos1);
                    for (int j = 1; j < cnt[i]; j++) putchar('a' + i);
                    putchar('\n');
                    goto cat;
                }
                pos2 = pos1 + 1;
                while (cnt[pos2] == 0) ++pos2;
                putchar('a' + i), putchar('a' + pos1);
                for (int j = 1; j < cnt[i]; j++) putchar('a' + i);
                putchar('a' + pos2);
                for (int j = 1; j <= n; j++) {
                    if (str[j] == 'a' + i) str[j] = 'z' + 1;
                    if (str[j] == 'a' + pos1) str[j] = 'z' + 1, pos1 = -1;
                    if (str[j] == 'a' + pos2) str[j] = 'z' + 1, pos2 = -1;
                }
                sort(str + 1, str + n + 1);
                for (int j = 1; str[j] != 'z' + 1; j++) putchar(str[j]);
                putchar('\n');
                goto cat;
            }
        cat:;
    }
    fwrite(_O, 1, _P - _O, stdout);
    return 0;
}