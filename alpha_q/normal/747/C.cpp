#include <bits/stdc++.h>
 
using namespace std;

const int N = 1e6 + 1e5 + 10;

int n, q;
int used = 0;
bitset <N> vis, vis2;
bitset <105> mark;
int now = 0;
int t[N], k[N], d[N];
vector <int> fre[N];

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d %d %d", t + i, k + i, d + i);
        vis[t[i]] = 1;
    }
    for (int i = 1; i < N - 10; ++i) {
        if (!vis[i] and !vis2[i]) continue;
        if (vis2[i]) {
            for (int j = 0; j < (int) fre[i].size(); ++j) {
                mark[fre[i][j]] = 0;
                --used;
            }
        }
        if (vis[i]) {
            ++now;
            if (used + k[now] <= n) {
                int sum = 0;
                for (int j = 1, l = 1; j <= n, l <= k[now]; ++j) {
                    if (!mark[j]) {
                        ++l;
                        sum += j;
                        mark[j] = 1;
                        fre[t[now] + d[now]].push_back(j);
                    }
                }
                vis2[t[now] + d[now]] = 1;
                used += k[now];
                printf("%d\n", sum);
            } else {
                puts("-1");
            }
        }
    }
    return 0;
}