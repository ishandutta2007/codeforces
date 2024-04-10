#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int64;
typedef long double ld;
const ld eps = 1e-09;
const int inf = 2000000000;

set <int> a;
int n, x;
int b[1500];
int sz[2000];
bool ss[2000];

int m;
vector <int> p;
bool dp[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        ss[b[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!ss[i]) {
            bool f = true;

            int cur = i;
            int tmp = 1;
            while (b[cur] != 0) {
                if (cur == x)
                    f = false;
                sz[cur] = tmp;
                cur = b[cur];
                ++tmp;
            }
            if (cur == x)
                f = false;

            sz[cur] = tmp;
            if (f) {
                ++m;
                p.pb(tmp);
            }
        }

    dp[0] = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 1100; j >= 0; --j)
            if (dp[j])
                dp[j + p[i]] = true;
    }

    int ans = 1;
    int cur = x;
    while (b[cur] != 0) {
        ++ans;
        cur = b[cur];
    }
    for (int i = 0; i < 1100; ++i)
        if (dp[i]) {
            printf("%d\n", i + ans);
        }
    return 0;
}