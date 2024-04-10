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

const int N = 1e5, S = 18;

int a[N + 10], f[N + 10][S + 10], vis[N + 10], tot, pr[N + 10];
vector<int> awsl[N + 10];
bool p[N + 10];

void Init() {
    for (int i = 2; i <= N; i++) {
        if (p[i] == 0) pr[++tot] = i;
        for (int j = i + i; j <= N; j += i) p[i] = 1;
    }
    for (int i = 1; i <= tot; i++)
        for (int j = pr[i]; j <= N; j += pr[i]) awsl[j].push_back(pr[i]);
}

void clear(int x) {
    for (auto i : awsl[x]) vis[i]--;
}

int query(int l, int r) {
    int ret = 0;
    for (int i = S; ~i; i--)
        if (f[l][i] && f[l][i] <= r) ret += (1 << i), l = f[l][i];
    return ret + 1;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init();
    int n = fr(), q = fr(), to = 0;
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i <= n; i++) {
        clear(a[i - 1]);
        while (to <= n) {
            int qwq = 0;
            to++;
            if (to > n) break;
            for (auto j : awsl[a[to]]) {
                if (vis[j]) qwq = 1;
                vis[j]++;
            }
            if (qwq) {
                clear(a[to]);
                break;
            }
        }
        f[i][0] = to, to--;
    }
    f[n + 1][0] = n + 1;
    for (int j = 1; j <= S; j++) {
        f[n + 1][j] = n + 1;
        for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
    }
    for (int i = 1, l, r; i <= q; i++) {
        fr(l), fr(r);
        printf("%d\n", query(l, r));
    }
    return 0;
}

/*
2|3 2|3 2|3 2
2 3|2 3|2 3|2

2 3 10 7 5 14

2 3|10 7|5 14
1 1 2 2 3 3

14 5|7 10 3|2
1 1 2 2 2 3
2|3 10 7|5 14
3 2 2 2 1 1
*/