#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXM = 21;

int N, M, D;
int sum[MAXN][MAXM];
bool bio[1 << MAXM];

void load() {
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; i++) {
        int sz; 
        scanf("%d", &sz);
        while (sz--) {
            int x;
            scanf("%d", &x);
            sum[x][i] = 1;
        }
    }
}

void dfs(int x) {
    if (bio[x]) return;
    bio[x] = true;
    for (int i = 0; i < M; i++) 
        if (x >> i & 1) dfs(x ^ 1 << i);
}

int solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++) 
            sum[i][j] += sum[i - 1][j];
        
    for (int i = 1; i + D - 1 <= N; i++) {
        int mask = 0;
        for (int j = 0; j < M; j++)
            if (sum[i - 1][j] == sum[i + D - 1][j]) 
                mask |= 1 << j;
        dfs(mask);
    }
    
    int sol = M;
    for (int i = 0; i < 1 << M; i++)
        if (!bio[i]) sol = min(sol, __builtin_popcount(i));
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}