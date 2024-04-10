#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, k;
pair <int, int> a[15000];
int dp[7100][7100];
int dp2[100000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= 3 * n; ++i)
        a[i].first = 86401;

    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &a[i].fir, &a[i].sec);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            dp[i][j] = inf;
    for (int i = 0; i <= 87000; ++i)
        dp2[i] = inf;
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            if (dp[i][j] != inf) {
                dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]);
                if (dp[i][j] <= a[i + 1].first)
                    dp[i + 1][j] = min(dp[i + 1][j], a[i + 1].first + a[i + 1].second);
                else dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1].second);
                if (dp[i][j] <= 90000)
                    if ((dp[i][j] <= a[i + 1].first) || (i == n))
                        dp2[dp[i][j]] = min(dp2[dp[i][j]], j);
            }
    int ans = 0;
    dp2[1] = 0;
    for (int x = 1; x <= 86400; ++x)
        if (dp2[x] != inf) {
            int l = 1;
            int r = n;
            while (r - l > 2) {
                int m = (l + r) / 2;
                if (a[m].first >= x)
                    r = m;
                else l = m;
            }
            bool f = false;
            for (int i = l; i <= r; ++i)
                if (a[i].first >= x) {
                    l = i;
                    f = true;
                    break;
                }
            if (!f)
                ans = max(ans, 86400 - x + 1);
            else
                ans = max(ans, a[l + k - dp2[x]].first - x);
        }
    cout << ans << endl;
    return 0;
}