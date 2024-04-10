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
int dp[55000][700];
vector <int> a[55000];
int64 ans;

void dfs(int v, int p) {
    for (int i = 0; i < a[v].size(); ++i)
        if (a[v][i] != p) {
            dfs(a[v][i], v);
            for (int j = 0; j < k; ++j)
                ans += int64(dp[v][j]) * int64(dp[a[v][i]][k - j - 1]);
            for (int j = 0; j < k; ++j)
                dp[v][j + 1] += dp[a[v][i]][j];
        }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for (int i = 0; i < n; ++i)
        dp[i][0] = 1;
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}