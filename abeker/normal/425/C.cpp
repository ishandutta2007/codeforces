#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXK = 305;
const int INF = 0x3f3f3f3f;

int N, M, S, E;
int a[MAXN];
int dp[MAXN][MAXK];
vector <int> V[MAXN];

void load() {
    scanf("%d%d%d%d", &N, &M, &S, &E);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= M; i++) {
        int x; scanf("%d", &x);
        V[x].push_back(i);
    }
}

int nxt(int pos, int val) {
    vector <int> :: iterator it = lower_bound(V[val].begin(), V[val].end(), pos);
    return it == V[val].end() ? INF : *it;  
}

int solve() {
    
    memset(dp[0], INF, sizeof dp[0]);
    dp[0][0] = 0;
    
    int sol = 0;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j * E + i < S; j++) {
            dp[i][j] = nxt(dp[i - 1][j - 1] + 1, a[i]);
            if (j * E + i + dp[i][j] <= S) sol = max(sol, j);
            if (i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}