#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, M;
vector <int> E[MAXN];
int color[MAXN];
int cnt[5];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

bool dfs(int x, int c) {
    if (color[x] != -1)
        return color[x] == c;
    color[x] = c;
    cnt[c]++;
    for (int i = 0; i < E[x].size(); i++)
        if (!dfs(E[x][i], c ^ 1)) return 0;
    return 1;
}

void solve() {
    if (!M) {
        printf("3 %I64d\n", (ll)N * (N - 1) * (N - 2) / 6);
        return;
    }
    
    memset(color, -1, sizeof color);
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        if (color[i] != -1) continue;
        memset(cnt, 0, sizeof cnt);
        if (!dfs(i, 0)) {
            puts("0 1");
            return;
        }
        for (int j = 0; j < 2; j++)
            sol += (ll)cnt[j] * (cnt[j] - 1) / 2;
    }
    
    if (sol) printf("1 %I64d\n", sol);
    else printf("2 %I64d\n", (ll)M * (N - 2));
}

int main() {
    load();
    solve();
    return 0;
}