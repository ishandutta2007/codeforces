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

const int N = 5e2, INF = 0x3f3f3f3f;

int n, k, ans, hd, tl, que[N + 10], cnt[N + 10];
pair<int, int> pre[N + 10];
bool vis[N + 10];

bool bfs() {
    for (int i = 0; i <= n; i++) pre[i].first = -1, cnt[i] = INF;
    hd = 1, tl = 0, que[++tl] = 0, cnt[0] = 0;
    while (hd <= tl) {
        int u = que[hd++];
        for (int i = 0; i <= k; i++)
            if (i <= u && (k - i) <= (n - u)) {
                int v = u + k - 2 * i;
                if (v < 1 || v > n) continue;
                if (cnt[u] + 1 < cnt[v]) cnt[v] = cnt[u] + 1, pre[v] = make_pair(u, i), que[++tl] = v;
            }
    }
    return cnt[n] != INF;
}

void dfs(int u) {
    if (pre[u].first == -1) return ;
    dfs(pre[u].first), printf("? ");
    int tot[] = {k - pre[u].second, pre[u].second};
    for (int i = 1; tot[0] >= 1 || tot[1] >= 1; i++)
        if (tot[vis[i]]) tot[vis[i]]--, vis[i] ^= 1, printf("%d ", i);
    puts(""), fflush(stdout), ans ^= fr();
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(k);
    if (bfs() == 0) return puts("-1"), fflush(stdout), 0;
    dfs(n), printf("! %d\n", ans), fflush(stdout);
    return 0;
}