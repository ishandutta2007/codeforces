#include <bits/stdc++.h>

using namespace std;

const int N = 2'007;

int n;
char tmp[N];
bitset <N> G[N], full;

void flip(int u)
{
    for (int i = 1; i <= n; ++i) {
        G[u][i] = G[u][i] ^ 1;
        G[i][u] = G[i][u] ^ 1;
    }
}

int sQ, eQ;
int Q[N];

bool check()
{
    bitset <N> vis = full;
    sQ = eQ = 0;

    Q[eQ++] = 1;
    vis[1] = 0;

    while (sQ < eQ) {
        int cur = Q[sQ++];
        auto cur_vis = vis & G[cur];

        int place = cur_vis._Find_first();
        while (place <= n) {
            Q[eQ++] = place;
            vis[place] = 0;
            place = cur_vis._Find_next(place);
        }
    }

    if (eQ < n) {
        return false;
    }

    vis = full;
    sQ = eQ = 0;

    Q[eQ++] = 1;
    vis[1] = 0;

    while (sQ < eQ) {
        int cur = Q[sQ++];
        auto cur_vis = vis & (G[cur] ^ full);

        int place = cur_vis._Find_first();
        while (place <= n) {
            Q[eQ++] = place;
            vis[place] = 0;
            place = cur_vis._Find_next(place);
        }
    }

    return eQ == n;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", tmp + 1);
        for (int j = 1; j <= n; ++j) {
            G[i][j] = tmp[j] - '0';
        }

        full[i] = 1;
    }

    if (check()) {
        puts("0 1");
        exit(0);
    }

    if (n <= 10) {
        int ans = 1000, cnt = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cur = __builtin_popcount(mask);
            if (cur > ans) {
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    flip(i + 1);
                }
            }

            if (check()) {
                if (cur < ans) {
                    ans = cur;
                    cnt = 0;
                }

                ++cnt;
            }

            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    flip(i + 1);
                }
            }
        }

        if (ans > n) {
            puts("-1");
        } else {
            for (int i = 1; i <= ans; ++i) {
                cnt *= i;
            }

            printf("%d %d\n", ans, cnt);
        }

        exit(0);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        flip(i);

        if (check()) {
            ++ans;
        }

        flip(i);
    }

    printf("1 %d\n", ans);
    return 0;
}