#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N;
vector <int> E[MAXN];
int opt[MAXN][2][2];
int dp[MAXN][MAXN][2];
int cnt[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
}

void dfs(int x, int p) {
    bool leaf = true;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) {
            dfs(E[x][i], x);
            cnt[x] += cnt[E[x][i]];
            leaf = false;
        }
        
    if (leaf) {
        cnt[x] = 1;
        dp[x][0][0] = dp[x][1][1] = INF;
        return;
    }
    
    int sum = 0, c = 0;
    opt[0][0][0] = opt[0][1][0] = 0;
    for (int i = 1; i <= cnt[x]; i++)   
        for (int j = 0; j < 2; j++)
            opt[i][j][c] = INF;
            
    for (int i = 0; i < E[x].size(); i++) {
        int tmp = E[x][i];
        if (tmp == p) continue;
        c ^= 1;
        sum += cnt[tmp];
        for (int l = 0; l < 2; l++)
            for (int j = 0; j <= sum; j++) {
                opt[j][l][c] = INF;
                for (int k = 0; k <= cnt[tmp] && k <= j; k++) 
                    if (j - k <= sum - cnt[tmp])
                        opt[j][l][c] = min(opt[j][l][c], opt[j - k][l][c ^ 1] + min(dp[tmp][k][l], dp[tmp][k][l ^ 1] + 1));
            }
    }
    
    for (int i = 0; i <= cnt[x]; i++)
        for (int j = 0; j < 2; j++)
            dp[x][i][j] = opt[i][j][c]; 
}

int solve() {
    int root = 0;
    for (int i = 1; i <= N; i++)
        if (E[i].size() > 1) {
            root = i;
            break;
        }
    dfs(root, 0);
    return dp[root][cnt[root] / 2][0];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}