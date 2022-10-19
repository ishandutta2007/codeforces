#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
pii p[MAXN];
int sol[MAXN];
int f[2 * MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
}

void update(int x) {
    for (; x < 2 * MAXN; x += x & -x)
        f[x]++;
}

int get(int x) {
    int ret = 0;
    for (; x; x -= x & -x)
        ret += f[x];
    return ret;
}

void solve() {
    sort(p + 1, p + N + 1);
    for (int i = 1; i <= N; i++) {
        int idx = p[i].second;
        for (int k = 1; k * (idx - 1) + 2 <= N && k < N; k++)
            sol[k] += get(k * idx + 1) - get(k * (idx - 1) + 1);
        if (p[i].first == p[i + 1].first) continue;
        for (int j = i; j && p[j].first == p[i].first; j--)
            update(p[j].second);
    }
    for (int i = 1; i < N; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}