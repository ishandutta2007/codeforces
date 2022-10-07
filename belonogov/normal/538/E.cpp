#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;

int n;
vector < int > e[N];
int dp[N][2][2];
int cnt[N];

int dfs(int v) {
    int sum = 0;
    for (auto u: e[v]) {
        sum += dfs(u);
    }
    sum = max(sum, 1);
    cnt[v] = sum;
    if (e[v].empty()) {
        dp[v][0][0] = dp[v][0][1] = dp[v][1][0] = dp[v][1][1] = 0;

    }
    else {
        
        //1 1     
        int tmp = INF;
        for (auto u: e[v])
            tmp = min(tmp, cnt[u] - 1 - dp[u][1][0]);
        dp[v][1][1] = cnt[v] - 1 - tmp;
        // 1 0
        tmp = 0;
        for (auto u: e[v])
            tmp += dp[u][1][1];
        dp[v][1][0] = tmp;
        // 0 0
        tmp = INF; 
        for (auto u: e[v])
            tmp = min(tmp, dp[u][0][1]);
        dp[v][0][0] = tmp; 
        // 0 1
        tmp = 0;
        for (int u: e[v])
            tmp += cnt[u] - 1 - dp[u][0][0];
        dp[v][0][1] = cnt[v] - 1 - tmp;
    }

    return sum;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
    }
}

void solve() {
    dfs(0);
    printf("%d %d\n", dp[0][1][1] + 1, dp[0][0][1] + 1);
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}