#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 500005;

int N;
int l[MAXN], r[MAXN];
vector <int> V;
int dp[2 * MAXN];
vector <int> E[2 * MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", l + i, r + i);
}

int get(int val) {
    return lower_bound(V.begin(), V.end(), val) - V.begin() + 1;
}

int solve() {
    for (int i = 0; i < N; i++) {
        V.push_back(l[i]);
        V.push_back(r[i]);
    }
    
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++) 
        E[get(r[i])].push_back(get(l[i]));
    
    int sol = 0;
    for (int i = 1; i <= V.size(); i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < E[i].size(); j++)
            dp[i] = max(dp[i], dp[E[i][j] - 1] + 1);
        sol = max(sol, dp[i]);
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}