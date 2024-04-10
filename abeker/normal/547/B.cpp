#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
pii p[MAXN];
bool bio[MAXN];
int dad[MAXN];
int sz[MAXN];
int maks = 1;
int sol[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i + 1;
    }
}

int find(int x) {
    return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
    if (rand() & 1) swap(x, y);
    x = find(x);
    y = find(y);
    dad[y] = x;
    sz[x] += sz[y];
    maks = max(maks, sz[x]);
}

void solve() {
    sort(p, p + N);
    for (int i = 1; i <= N; i++) {
        dad[i] = i;
        sz[i] = 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        int pos = p[i].second;
        if (bio[pos - 1]) join(pos - 1, pos);
        if (bio[pos + 1]) join(pos + 1, pos);
        bio[pos] = true;
        sol[maks] = max(sol[maks], p[i].first);
    }
    for (int i = N; i; i--) 
        sol[i] = max(sol[i], sol[i + 1]);
    for (int i = 1; i <= N; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}