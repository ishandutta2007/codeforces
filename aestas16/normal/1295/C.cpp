#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    f ? a = -a : 0;
}
template <class T, class ...Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5, ALPHA = 26;

char S[N + 10], T[N + 10];

#define h(c) ((c) - 'a')

struct SubSeqAM {
    int nxt[N + 10][ALPHA];
    int *operator [] (const int &i) { return nxt[i]; }
    void build(char *s) {
        int len = strlen(s + 1);
        memset(nxt[len], 0, sizeof(nxt[len]));
        for (int i = len; i; i--) memcpy(nxt[i - 1], nxt[i], sizeof(nxt[i - 1])), nxt[i - 1][h(s[i])] = i;
    }
} A;

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        scanf("%s%s", S + 1, T + 1);
        int n = strlen(T + 1), ans = 1;
        A.build(S);
        for (int i = 1, u = 0; i <= n && ans <= n; i++)
            if (A[u][h(T[i])]) u = A[u][h(T[i])];
            else ans++, i--, u = 0;
        printf("%d\n", ans > n ? -1 : ans);
    }
    return 0;
}