#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, M;
vector <int> E[MAXN];
int dp[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
}

int dfs(int x) {
    if (dp[x]) return dp[x];
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] < x) dp[x] = max(dp[x], dfs(E[x][i]));
    return ++dp[x]; 
}

ll solve() {
    ll sol = 0;
    for (int i = 1; i <= N; i++)
        sol = max(sol, (ll)dfs(i) * E[i].size());
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}