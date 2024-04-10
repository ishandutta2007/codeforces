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

const int N = 1e6 + 5;

char s[N];
int n, m, k, fir[N], sec[N], cnt[N], sa[N], qwq[N];

void SA() {
    for (int i = 1; i <= n; i++) {
        fir[i] = s[i] - '0' + 1;
        cnt[fir[i]]++;
    }
    for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[fir[i]]] = i, cnt[fir[i]]--;
    for (int P = 1, ss = 0; P <= n; P <<= 1, ss = 0) {
        for (int i = n - P + 1; i <= n; i++) sec[++ss] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > P) sec[++ss] = sa[i] - P;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[fir[i]]++;
        for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[fir[sec[i]]]] = sec[i], cnt[fir[sec[i]]]--, sec[i] = 0;
        swap(fir, sec), ss = 1, fir[sa[1]] = 1;
        for (int i = 2; i <= n; i++)
            if (sec[sa[i]] == sec[sa[i - 1]] && sec[sa[i] + P] == sec[sa[i - 1] + P])
                fir[sa[i]] = ss;
            else
                fir[sa[i]] = ++ss;
        if (ss == n) break;
        m = ss;
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(k), scanf("%s", s + 1), m = 122 - 48 + 1;
    for (int i = 1; i <= n; i++) s[i + n] = s[i];
    n <<= 1;
    SA();
    // n >>= 1;
    for (int i = 1; i <= n; i++) qwq[sa[i]] = i;
    // for (int i = 1; i <= n; i++) printf("%d ", qwq[i]);
    for (int i = 2; i <= n; i++) 
        if (s[i] >= s[1]) {
            if (qwq[i] > qwq[1]) {
                for (int l = 1, j = 1; j <= k; l++, j++) {
                    if (l == i) l = 1;
                    putchar(s[l]);
                }
                return 0;
            }
        }
    for (int l = 1, j = 1; j <= k; l++, j++) {
        if (l == n + 1) l = 1;
        putchar(s[l]);
    }
    return 0;
}