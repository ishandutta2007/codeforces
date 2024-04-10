#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N;
vector <int> E[MAXN];
bool bio[MAXN];
vector <int> V;
int sz[MAXN], maks[MAXN];
int sol[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p) {
    V.push_back(x);
    maks[x] = 0;
    sz[x] = 1;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (bio[nxt] || nxt == p) continue;
        dfs(nxt, x);
        sz[x] += sz[nxt];
        maks[x] = max(maks[x], sz[nxt]);
    }
}

void centroid(int x, int p, int d) {
    V.clear();
    dfs(x, p);
    int best = -1;
    for (int i = 0; i < V.size(); i++) {
        maks[V[i]] = max(maks[V[i]], sz[x] - sz[V[i]]);
        if (best == -1 || maks[V[i]] < maks[best]) best = V[i];
    }
    x = best;
    sol[x] = d;
    bio[x] = true;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (bio[nxt]) continue;
        centroid(nxt, x, d + 1);
    }
}

void solve() {
    centroid(1, 0, 0);
    for (int i = 1; i <= N; i++)
        printf("%c ", 'A' + sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}