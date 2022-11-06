#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 300100;
int mi[V], mx[V];
int tr[V * 2];
int N;
int add(int k, int v) {
    while (k <= N) {
        tr[k] += v;
        k += k & -k;
    }
}
int read(int k) {
    int res = 0;
    while (k) {
        res += tr[k];
        k -= k & -k;
    }
    return res;
}

struct Event {
    int l, v;
};
vector<Event> e[2 * V];

void event(int l, int r, int v) {
    Event ne;
    ne.l = l;
    ne.v = v;
    e[r].push_back(ne);
}

int last[V], pre[2 * V];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n + m; ++i) e[i].clear();
        for (int i = 1; i <= n; ++i) mi[i] = mx[i] = i;
        for (int i = 1; i <= n; ++i) last[i] = n - i + 1, pre[i] = -1;
        for (int i = n + 1; i <= n + m; ++i) {
            int x;
            scanf("%d", &x);
            mi[x] = 1;
            event(last[x] + 1, i - 1, x);
            pre[i] = last[x];
            last[x] = i;
        }
        for (int i = 1; i <= n; ++i) {
            event(last[i] + 1, n + m, i);
        }
        N = n + m;
        for (int i = 1; i <= N; ++i) tr[i] = 0;
        for (int i = 1; i <= n + m; ++i) {
            add(N - i + 1, 1);
            if (pre[i] != -1) add(N - pre[i] + 1, -1);
            for (int j = 0; j < e[i].size(); ++j) {
                int l = e[i][j].l;
                int r = i;
                int x = e[i][j].v;
                //printf("E %d %d %d\n", l, r, x);
                if (l <= r) {
                    int cnt = read(N - l + 1);
                    mx[x] = max(mx[x], cnt + 1);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", mi[i], mx[i]);
    }
    return 0;
}

/*
5 4
3 5 1 4
4 3
1 2 4
*/