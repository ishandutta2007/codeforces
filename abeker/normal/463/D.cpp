#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1005;
const int MAXK = 10;

int N, K;
int pos[MAXN][MAXK];
vector <int> v[MAXN];
int dp[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) 
        for (int j = 0; j < N; j++) {
            int x; scanf("%d", &x);
            pos[--x][i] = j;
        }
}

inline bool check(int x, int y) {
    for (int i = 0; i < K; i++) 
        if (pos[x][i] >= pos[y][i]) return 0;
    return 1;
}

int rec(int x) {
    int &ref = dp[x];
    if (ref != -1) return ref;
    for (int i = 0; i < v[x].size(); i++) 
        ref = max(ref, rec(v[x][i]));
    return ++ref;
}

int solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            if (check(i, j)) v[i].push_back(j);
    memset(dp, -1, sizeof dp);
    int sol = 0;
    for (int i = 0; i < N; i++) 
        sol = max(sol, rec(i));     
    return sol + 1;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}