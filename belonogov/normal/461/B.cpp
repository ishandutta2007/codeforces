#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e5 + 10;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int n;
int p[N];
int c[N];
vector < int > e[N];
long long dp[N][2];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
} 

void dfs(int v) {
    dp[v][0] = dp[v][1] = 0;
    dp[v][c[v]] = 1;
    for (int u : e[v]) {
        dfs(u);
        long long r0, r1;
        r0 = (dp[v][0] * (dp[u][0] + dp[u][1])) % MOD;
        r1 = (dp[v][1] * dp[u][0] + dp[v][0] * dp[u][1] + dp[v][1] * dp[u][1]) % MOD;
        dp[v][0] = r0;
        dp[v][1] = r1;
    }
}

void solve() {
    for (int i = 0; i < n - 1; i++) {
        e[p[i]].pb(i + 1);
    }
    dfs(0);
}

void printAns() {
    printf("%lld", dp[0][1]);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}