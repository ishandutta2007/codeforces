#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

bool vis[200005];
int to[400005];
LL deg[200005];
int dep[200005];
vector<int> G[200005];
LL used[400005];
LL rem[200005];

void dfs(int v, int par, int ce)
{
	vis[v] = true;
	dep[v] = dep[par] + 1;
	rem[v] = deg[v];
	rep(i, G[v].size()) {
		int e = G[v][i], u = to[e];
		if(u == par || vis[u]) continue;
		dfs(u, v, e ^ 1);
		rem[v] += used[e];
	}
	if(ce != -1) {
		used[ce] = -rem[v];
		used[ce ^ 1] = rem[v];
		rem[v] = 0;
	}
}
int main()
{
	int n, m;
	scanf("%d", &n);
	rep1(i, n) scanf("%I64d", &deg[i]);
	scanf("%d", &m);
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(i << 1);
		G[v].push_back(i << 1 | 1);
		to[i << 1] = v;
		to[i << 1 | 1] = u;
	}
	memset(vis, false, sizeof(vis));
	dfs(1, 0, -1);
	if(rem[1] == 0LL) {
		printf("Possible\n");
		rep(i, m) printf("%I64d\n", used[i << 1]);
	} else printf("Impossible\n");
	return 0;
}