#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N;
vector <int> E[MAXN], sol;
int val[MAXN];
int cnt[2];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) 
        scanf("%d", val + i);
    for (int i = 1; i <= N; i++) {
        int goal; scanf("%d", &goal);
        val[i] ^= goal;
    }
}

void dfs(int x, int p, int d) {
    int tmp = cnt[d] ^ val[x];
    if (tmp) sol.push_back(x);
    cnt[d] ^= tmp;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x, d ^ 1);
    cnt[d] ^= tmp;
}

void solve() {
    dfs(1, 0, 0);
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++) 
        printf("%d\n", sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}