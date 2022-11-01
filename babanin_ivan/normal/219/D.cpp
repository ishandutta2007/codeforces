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

int n;
vector <pair <int, int> > a[300000];
int dp[300000];
int path[300000];
int res = inf;
int depth[300000];
vector <int> b;

void dfs(int v, int p, int temp, int d) {
    int sum = 0;
    path[v] = temp;
    depth[v] = d;
    for (int i = 0; i < a[v].size(); ++i)
        if (a[v][i].first != p) {
            if (a[v][i].first == a[v][i].second) 
                dfs(a[v][i].first, v, temp + 1, d + 1);
            else dfs(a[v][i].first, v, temp, d + 1), ++sum;
            sum += dp[a[v][i].first];
        }
    dp[v] = sum;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        a[x].pb(mp(y, y));
        a[y].pb(mp(x, y));
    }
    dfs(0, -1, 0, 0);
    for (int i = 0; i < n; ++i) {
        if (res > (dp[0] + path[i] - (depth[i] - path[i]))) {
            b.clear();
            res = (dp[0] + path[i] - (depth[i] - path[i]));
        }
        if (res == (dp[0] + path[i] - (depth[i] - path[i])))
            b.pb(i);
    }
    printf("%d\n", res);
    for (int i = 0; i < b.size(); ++i)
        printf("%d ", b[i] + 1);
    return 0;
}