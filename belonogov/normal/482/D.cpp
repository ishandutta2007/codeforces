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
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const long long MOD = 1e9 + 7;

int n;
int p[N];
vector < int > e[N];
long long dp[N][2];

void dfs(int v) {
    dp[v][0] = 1;
    dp[v][1] = 0;
    long long x = 1;
    long long y[2];
    y[0] = 1;
    y[1] = 0;
    for (auto u: e[v]) {
        dfs(u); 
        double r0 = (dp[v][0] * (dp[u][0] + 1) + dp[v][1] * dp[u][1]) % MOD;
        double r1 = (dp[v][0] * dp[u][1] + dp[v][1] * (dp[u][0] + 1)) % MOD;
        dp[v][0] = r0;
        dp[v][1] = r1;
        x = (x * (dp[u][0] + 1)) % MOD;
        long long y1 = (y[1] + dp[u][1] * y[0]) % MOD;
        long long y0 = (y[0] + dp[u][1] * y[1]) % MOD;
        y[0] = y0;
        y[1] = y1;
    }
    //db2(x, y[1]);
    //db2(dp[v][0], dp[v][1]);
    dp[v][0] = (dp[v][0] * 2 - x + MOD) % MOD;
    dp[v][1] = (dp[v][1] * 2 - y[1] + MOD) % MOD;
    swap(dp[v][0], dp[v][1]);
}

void read() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v;
        scanf("%d", &v);
        v--;
        e[v].pb(i);
    }
}

void solve() {
    dfs(0);
    //for (int i = 0; i < n; i++)
        //db2(dp[i][0], dp[i][1]);
    cout << (dp[0][0] + dp[0][1]) % MOD << endl;

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}