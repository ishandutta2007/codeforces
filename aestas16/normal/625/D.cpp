#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5;

int n, tmp[N + 10], ans[N + 10];
char str[N + 10];

bool chk() {
    for (register int i = 1; i <= n; i++) ans[i] = 0, tmp[i] = str[i];
    for (register int l = 1 + (tmp[1] == 0), r = n; l <= r; l++, r--) {
        if (tmp[l] != tmp[r]) {
            if (tmp[l] - tmp[r] >= 10) tmp[r] += 10, tmp[r - 1]--;
            if (tmp[l] - tmp[r] == 1) tmp[l]--, tmp[l + 1] += 10;
            if (tmp[l] != tmp[r]) return 0;
        }
        if (l == r) {
            if (tmp[l] & 1) return 0;
            ans[l] = tmp[l] / 2;
        } else ans[l] = tmp[l] - tmp[r] / 2, ans[r] = tmp[r] / 2;
    }
    for (register int i = 1; i <= n; i++) if (ans[i] < 0 || ans[i] > 9) return 0;
    return 1;
}

void print() {
    for (register int i = 1, f = 0; i <= n; i++) {
        if (ans[i]) f = 1;
        if (f) printf("%d", ans[i]);
    }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    scanf("%s", str + 1), n = strlen(str + 1);
    for (register int i = 1; i <= n; i++) str[i] -= '0';
    if (str[1] == str[n] && chk()) return print(), 0;
    if (n > 1) {
        str[1]--, str[2] += 10;
        if (chk()) return print(), 0;
    }
    return puts("0"), 0;
}