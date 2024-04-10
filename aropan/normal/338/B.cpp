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

const int MAXN = 100007;
const int INF = 1e+9 + 7;

vector < int > e[MAXN];
int p[MAXN];
int f[MAXN];
vector < pair <int, int> > v[MAXN];
int n, m, k;
int ans;

void fdfs(int x, int prev)
{
    f[x] = p[x]? k : INF;
    v[x].clear();
    v[x].push_back(make_pair(f[x], x));
    v[x].push_back(make_pair(INF, INF));
    for (int i = 0; i < (int)e[x].size(); i++)
    {
        int y = e[x][i];
        if (y == prev)
            continue;
        fdfs(y, x);
        f[x] = min(f[y] - 1, f[x]);
        v[x].push_back(make_pair(f[y] - 1, y));
        sort(v[x].begin(), v[x].end());
        v[x].pop_back();
    }
}

void sdfs(int x, int prev, int l)
{
    ans += min(l, f[x]) >= 0;
    for (int i = 0; i < (int)e[x].size(); i++)
    {
        int y = e[x][i];
        if (y == prev)
            continue;
        sdfs(y, x, min(l, v[x][v[x][0].second == y].first) - 1);
    }
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        p[x] = true;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    
    for (int i = 1; i <= 1; i++)
    {
        ans = 0;
        fdfs(i, 0);
        sdfs(i, 0, INF);
        cout << ans << endl;
    }
	return 0;
}