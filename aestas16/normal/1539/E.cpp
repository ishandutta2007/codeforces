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

const int N = 1e5, INF = 0x7f7f7f7f;

int d[N + 10][5], f[N + 10][5], ch[N + 10][5];
bool s[N + 10][5];

struct Node {
    int v, id;
    bool operator < (const Node &rhs) const { return v < rhs.v; }
};
multiset<Node> S[2];
#define it multiset<Node>::iterator

void dfs(int tot, bool k) {
    if (tot == 1) return (void)(printf("%d ", k));
    dfs(tot - 1, s[tot][k]);
    printf("%d ", k);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n = fr(), m = fr();
    S[0].insert((Node){0, 0}), S[1].insert((Node){0, 0});
    for (int T = 1, x, l, r; T <= n; T++) {
        fr(x), S[0].insert((Node){x, T}), S[1].insert((Node){x, T});
        for (int k = 0; k <= 1; k++) {
            fr(l), fr(r);
            for (it i = S[k].begin(), tmp; i != S[k].end();) {
                if (i->v >= l) break;
                ch[i->id][k] = T - 1, tmp = i, i++, S[k].erase(tmp);
            }
            if (S[k].size()) {
                it i = (--S[k].end()), tmp;
                while (1) {
                    if (i->v <= r) break;
                    ch[i->id][k] = T - 1;
                    if (i == S[k].begin()) {
                        S[k].erase(i);
                        break;
                    }
                    tmp = i, i--, S[k].erase(tmp);
                }
            }
        }
    }
    for (int k = 0; k <= 1; k++)
        for (it i = S[k].begin(); i != S[k].end(); i++) ch[i->id][k] = n;
    f[0][0] = ch[0][1], f[0][1] = ch[0][0];
    for (int i = 1; i <= n; ++i) {
        f[i][0] = f[i][1] = -INF;
        if (f[i - 1][0] > 0) {
            if (ch[i][0] >= i && (f[i][0] < f[i - 1][0])) f[i][0] = f[i - 1][0], d[i][0] = i - 1;
            if (ch[i][1] >= i && (f[i][1] < ch[i - 1][0])) f[i][1] = ch[i - 1][0], d[i][1] = i - 1;
        }
        if (f[i - 1][1] > 0) {
            if (ch[i][1] >= i && (f[i][1] < f[i - 1][1])) f[i][1] = f[i - 1][1], d[i][1] = i - 1, s[i][1] = 1;
            if (ch[i][0] >= i && (f[i][0] < ch[i - 1][1])) f[i][0] = ch[i - 1][1], d[i][0] = i - 1, s[i][0] = 1;
        }
        if (f[i][0] < i) f[i][0] = -INF;
        if (f[i][1] < i) f[i][1] = -INF;
    }
    if (f[n][0] >= n)
        puts("YES"), dfs(n, 0);
    else if (f[n][1] >= n)
        puts("YES"), dfs(n, 1);
    else puts("NO");
    return 0;
}