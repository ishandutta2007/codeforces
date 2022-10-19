#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
int u[MAXN], v[MAXN];
vector <int> E[MAXN];
int dp[MAXN];

int dfs(int x) {
    if (dp[x]) return dp[x];
    for (int i = 0; i < E[x].size(); i++)
        dp[x] = max(dp[x], dfs(E[x][i]));
    return ++dp[x];
}

bool check(int k) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 0; i < k; i++)
        E[u[i]].push_back(v[i]);
    
    for (int i = 1; i <= N; i++)
        if (dfs(i) == N) return true;
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d", u + i, v + i);
    
    int lo = 0, hi = M + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    printf("%d\n", lo > M ? -1 : lo);
    
    return 0;
}