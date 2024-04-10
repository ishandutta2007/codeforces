#include <bits/stdc++.h>

const int N = 7, B = 10;
const int M = 10000000;

long long n, m;

std::bitset<M> ex[2];
int cnt[2][B][M / B];

void dfs1(int k, int now, int tp) {
    if (k == N) {
        ex[tp].set(now);
        return;
    }
    int lst = now % B;
    for (int i = 0; i < B; ++i) {
        if (lst != i && ((k & 1) ^ (lst < i) ^ tp)) {
            dfs1(k + 1, now * B + i, tp);
        }
    }
}

void dfs2(int k, int now, int tp) {
    if (k == N) {
        if (now % n == 0) {
            if (!m) {
                std::cout << now << "\n";
                exit(0);
            }
            --m;
        }
        return;
    }
    int lst = now % B;
    for (int i = 0; i < B; ++i) {
        if (lst != i && (((N - k) & 1) ^ (lst < i) ^ tp)) {
            dfs2(k + 1, now * B + i, tp);
        }
    }
}

void dfs3(int k, int now, int tp) {
    if (k == N) {
        int lst = now % B;
        for (int i = 0; i < B; ++i) {
            if (lst != i && ((lst < i) ^ tp)) {
                long long v = (1ll * now * M + i * (M / B)) % n;
                v = v ? n - v : 0;
                if (v < M / B) {
                    if (m >= cnt[tp][i][v]) {
                        m -= cnt[tp][i][v];
                    } else {
                        for (long long x = v; x < M / B; x += n) {
                            long long t = x + i * (M / B);
                            if (ex[tp][t]) {
                                if (!m) {
                                    std::cout << 1ll * now * M + t << "\n";
                                    exit(0);
                                }
                                --m;
                            }
                        }
                    }
                }
            }
        }
        return;
    }
    int lst = now % B;
    for (int i = 0; i < B; ++i) {
        if (lst != i && (((N - k) & 1) ^ (lst < i) ^ tp)) {
            dfs3(k + 1, now * B + i, tp);
        }
    }
}

int main() {
    std::cin >> n >> m;
    --m;

    for (int i = 0; i < B; ++i) {
        dfs1(1, i, 0);
        dfs1(1, i, 1);
    }
    for (int op = 0; op < 2; ++op) {
        for (int i = 0; i < B; ++i) {
            for (int j = 0; j < M / B; ++j) {
                cnt[op][i][j % n] += ex[op][i * (M / B) + j];
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int v = 1; v < B; ++v) {
            dfs2(N - i + 1, v, ((N - i) & 1) ^ 1);
            if (i > 1) {
                dfs2(N - i + 1, v, (N - i) & 1);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int v = 1; v < B; ++v) {
            dfs3(N - i + 1, v, ((N - i) & 1) ^ 1);
            dfs3(N - i + 1, v, (N - i) & 1);
        }
    }
    std::cout << -1 << "\n";
}