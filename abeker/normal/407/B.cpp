#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int N;
int p[MAXN];
int dp[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i);
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int solve() {
    for (int i = 1; i <= N; i++) {
        if (p[i] == i) {
            dp[i] = 1;
            continue;
        }
        memset(bio, false, sizeof bio);
        vector <int> pos;
        int x = p[i];
        for (; ; x = p[x]) {
            pos.push_back(x);
            bio[x] = true;
            if (p[x] == x) break;
        }
        dp[i] = (int)pos.size() + 1 + i - x;
        for (int j = x; j < i; j++)
            if (!bio[j]) dp[i] = add(dp[i], dp[j]);
    }
    
    int sol = N;
    for (int i = 1; i <= N; i++)
        sol = add(sol, dp[i]);
        
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}