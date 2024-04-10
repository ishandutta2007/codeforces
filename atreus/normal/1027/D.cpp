#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int inf = 1e9;

int c[maxn], p[maxn];

int visited[maxn], cur[maxn];

int Min;

void dfs (int u) {
	visited[u] ++;
	if (cur[u]) {
		Min = min (Min, c[u]);
	}
	cur[u] = 1;
	if (!visited[p[u]] or (cur[p[u]] and visited[p[u]] <= 1)) {
		dfs (p[u]);
	}
	cur[u] = 0;
}

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			Min = inf;
			dfs (i); 
			if (Min == inf)
				Min = 0;
			ans += Min;
		}
	}
	cout << ans << endl;
}