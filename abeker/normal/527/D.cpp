#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N;
int x[MAXN], w[MAXN];
vector <int> in[2 * MAXN], out[2 * MAXN];
vector <int> V;
int dp[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, w + i);
}

int solve() {
    for (int i = 0; i < N; i++) {
        V.push_back(x[i] - w[i]);
        V.push_back(x[i] + w[i]);
    }
    sort(V.begin(), V.end());
    
    for (int i = 0; i < N; i++) {
        in[lower_bound(V.begin(), V.end(), x[i] - w[i]) - V.begin()].push_back(i);
        out[lower_bound(V.begin(), V.end(), x[i] + w[i]) - V.begin()].push_back(i);
    }
    
    int maks = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < out[i].size(); j++)
            maks = max(maks, dp[out[i][j]]);
        for (int j = 0; j < in[i].size(); j++)
            dp[in[i][j]] = maks + 1;
    }
    
    return maks;    
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}