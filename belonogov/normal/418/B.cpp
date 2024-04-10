#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = -1;
const int maxM = 100 + 5;
const long long inf = 2e18;

struct Person {
    int x, k, mask;
};

long long dp[2][1 << 20];
Person b[maxM];

bool cmp(Person a, Person b) {
    return a.k < b.k;
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m, cnt, x;
    long long B;
    long long ans = inf;
    scanf("%d%d", &m, &n);
    cin >> B;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &b[i].x, &b[i].k, &cnt);
        b[i].mask = 0;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &x); x--;
            b[i].mask |= (1 << x);
        }
    }
    sort(b, b + m, cmp);
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++) {
        memset(dp[1], 63, sizeof(dp[1]));
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[0][mask] > inf) continue;
            dp[1][mask] = min(dp[1][mask], dp[0][mask]);
            dp[1][mask | b[i].mask] = min(dp[1][mask | b[i].mask], dp[0][mask] + b[i].x);
        }
        ans = min(ans, dp[1][(1 << n) - 1] + b[i].k * B);
        for (int mask = 0; mask < (1 << n); mask++)
            dp[0][mask] = dp[1][mask];
    }

    if (ans == inf)
        cout << "-1\n";
    else
        cout << ans << endl;
    return 0;
}