#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
pii p[MAXN];
int w[MAXN];
queue <int> Q[2 * MAXN];
int idx[MAXN], pos[MAXN];
int f[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
    for (int i = 0; i < N; i++) {
        scanf("%d", w + i);
        Q[w[i] + MAXN].push(i);
    }
}

void bye() {
    puts("NO");
    exit(0);
}

void update(int x, int val) {
    for (++x; x < MAXN; x += x & -x)
        f[x] = max(f[x], val);
}

int get(int x) {
    int ret = -1;
    for (++x; x; x -= x & -x)
        ret = max(ret, f[x]);
    return ret;
}

void solve() {
    sort(p, p + N);
    for (int i = 0; i < N; i++) {
        int tmp = p[i].second - p[i].first + MAXN;
        if (Q[tmp].empty()) bye();
        idx[i] = Q[tmp].front();
        Q[tmp].pop();
    }
    
    memset(f, -1, sizeof f);
    for (int i = 0; i < N; i++) {
        int maks = get(p[i].second);
        if (maks > idx[i]) bye();
        update(p[i].second, idx[i]);
        pos[idx[i]] = i;
    }
    
    puts("YES");
    for (int i = 0; i < N; i++)
        printf("%d %d\n", p[pos[i]].first, p[pos[i]].second);
}

int main() {
    load();
    solve();
    return 0;
}