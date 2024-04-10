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
const int maxn = 1000 + 10;
const int inf = 1e9;
const int MOD = 1e9 + 7;

long long dp[maxn];
int p[maxn];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = (dp[i] + dp[i] - dp[p[i]] + 2 + MOD) % MOD;
    }
    cout << dp[n] << endl;

    return 0;
}