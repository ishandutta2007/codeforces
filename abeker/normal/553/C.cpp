#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int MOD = 1000000007;

int N, M;
vector < pii > E[MAXN];
int color[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back(pii(b, c));
        E[b].push_back(pii(a, c));
    }
}

bool dfs(int x, int c) {
    if (color[x] != -1) 
        return color[x] == c;
    color[x] = c;
    for (int i = 0; i < E[x].size(); i++)
        if (!dfs(E[x][i].first, c == E[x][i].second))                                                                                                                                                                                                                                                                                                                                                                                                                                                               
            return 0;
    return 1;
}

int solve() {
    memset(color, -1, sizeof color);
    int cnt = -1;
    for (int i = 1; i <= N; i++) {
        if (color[i] != -1) continue;
        if (!dfs(i, 0)) return 0;
        cnt++;
    }
    int sol = 1;
    while (cnt--) sol = sol * 2 % MOD;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}