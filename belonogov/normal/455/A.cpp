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

int n;
int a[N];
int cnt[N + 10];
long long dp[N + 10];

void read() {
    if (scanf("%d", &n) != 1) exit(0);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    for (int i = 0; i < N; i++) {
        dp[i + 2] = max(dp[i + 2], cnt[i + 1] * 1ll * (i + 1) + dp[i]);
        dp[i + 3] = max(dp[i + 3], cnt[i + 2] * 1ll * (i + 2) + dp[i]);
    }
}

void printAns() {
    printf("%lld\n", dp[N]);
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
        }
    }
    else {
        stress();
    }

    return 0;
}