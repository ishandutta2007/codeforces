#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, K;
bool univ[MAXN];
vector <int> E[MAXN];
int subtree[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < 2 * K; i++) {
        int x;
        scanf("%d", &x);
        univ[x] = true;
    }
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
}

ll dfs(int x, int p) {
    ll res = 0;
    subtree[x] = univ[x];
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) continue;
        res += dfs(nxt, x);
        subtree[x] += subtree[nxt];
    }
    res += min(subtree[x], 2 * K - subtree[x]);
    return res;
}

int main() {
    load();
    printf("%I64d\n", dfs(1, 0));
    return 0;
}