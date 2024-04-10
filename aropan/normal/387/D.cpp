#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 1005;
const int INF = (int)1e+9 + 7;

int n, m;
vector <int> a[MAXN];
int c[MAXN];
int prev[MAXN];
int loop[MAXN];
int upd[MAXN], cnt;

bool dfs(int x, int r)
{
    if (upd[x] == cnt) {
        return false;
    }
    upd[x] = cnt;
    for (int lvl = 0; lvl < 2; ++lvl) {
        for (size_t i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            if (y != r && (prev[y] == 0 || (lvl && dfs(prev[y], r)))) {
                prev[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        if (x != y) {
            c[x] += 1;
            c[y] += 1;
        } else {
            loop[x] = true; 
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int res = 2 * (n - 1) - c[i];
        if (!loop[i]) {
            res += 1;
        }
        for (int j = 1; j <= n; ++j) {
            prev[j] = 0;
        }
        res += m - c[i] - (int)loop[i];
        for (int j = 1; j <= n; ++j)
            if (i != j) {
                cnt++;
                res -= (int)dfs(j, i);
            }
        for (int j = 1; j <= n; ++j)
            if (!prev[j] && j != i) {
                res += 1;
            }
        ans = min(ans, res);
    }
    cout << ans << endl;


	return 0;
}