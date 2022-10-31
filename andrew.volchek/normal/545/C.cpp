#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld lond double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const int maxn = 100005;
const ll inf = 1e16;

ll x[maxn], h[maxn];

int dp[maxn][2];

int main() {
    //freopen("a.in", "r", stdin);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        x[i] = u;
        h[i] = v;
    }

    x[0] = -inf;
    h[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        if (x[i - 1] + h[i - 1] < x[i] - h[i]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
        }

        if (x[i - 1] < x[i] - h[i]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
        }

        if (x[i - 1] + h[i - 1] < x[i]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][1]);
        }


        dp[i][1] = dp[i - 1][0] + 1;

        if (x[i - 1] + h[i - 1] < x[i]) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
        }
    }

    cout << max(dp[n][0], dp[n][1]);


    return 0;
}