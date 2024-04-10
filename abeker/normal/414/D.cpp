#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int M, K, P;
vector <int> E[MAXN];
int depth[MAXN];
ll sum[MAXN];

void load() {
    scanf("%d%d%d", &M, &K, &P);
    for (int i = 1; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p, int d) {
    depth[x] = d;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x, d + 1);
}

bool check(int val) {
    for (int i = 2; i + val - 1 <= M; i++) 
        if ((ll)val * depth[i + val - 1] - sum[i + val - 1] + sum[i - 1] <= (ll)P)
            return true;
    return false;
}

int solve() {
    dfs(1, 0, 0);
    sort(depth + 1, depth + M + 1);
    for (int i = 1; i <= M; i++)    
        sum[i] = sum[i - 1] + (ll)depth[i];
    int lo = 0, hi = min(K, M - 1);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}