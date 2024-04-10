#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, X, Y;
vector <int> E[MAXN];
int dp[MAXN][2];
int opt[MAXN];

void load() {
    scanf("%d%d%d", &N, &X, &Y);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p) {
    int sum = 0, mini1 = MAXN, mini2 = MAXN;
    bool leaf = true;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) continue;
        leaf = false;
        dfs(nxt, x);
        sum += opt[nxt];
        int tmp = dp[nxt][0] - opt[nxt];
        if (tmp <= mini1) {
            mini2 = mini1;
            mini1 = tmp;
        }
        else if (tmp < mini2) 
            mini2 = tmp;
    }
    
    dp[x][0] = sum + mini1;
    dp[x][1] = sum + mini1 + mini2 - 1;
    
    opt[x] = min(dp[x][0], dp[x][1]);    
    if (leaf) dp[x][0] = opt[x] = 1;
}

ll solve() {
    if (X == Y) return (ll)(N - 1) * X;
    
    if (X > Y) {
        bool ok = false;
        for (int i = 1; i <= N; i++)
            if (E[i].size() == N - 1) ok = true;
        return (ll)(N - 2) * Y + (ll)(ok ? X : Y);
    }
    
    dfs(1, 0);    
    
    return (ll)(opt[1] - 1) * Y + (ll)(N - opt[1]) * X;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}