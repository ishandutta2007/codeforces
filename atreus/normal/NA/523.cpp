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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;
int n;

int sz[maxn];

bool visited[maxn], mark[maxn];

char ans[maxn];

vector <int> t[maxn];

int dfs (int u, int par = -1) {
	sz[u] = 1;
	for (auto w : t[u]) {
		if (w != par and !mark[w]) {
			sz[u] += dfs (w, u);
		}
	}
	return sz[u];
}

void centroidDecomposition (int x, int now) {
	int Max = dfs (x), par = -1;
	while (true) {
		bool found = 0;
		for (auto w : t[x]) {
			if (par != w and !mark[w] and sz[w] > Max / 2) {
				par = x;
				x = w;
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
	mark[x] = 1;
	ans[x] = (char)(now + 'A');
	for (auto w : t[x]) {
		if (!mark[w]) {
			centroidDecomposition (w, now + 1);
		}
	}
}

void addEdge (int u, int w) {
	t[u].PB (w);
	t[w].PB (u);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		addEdge (u, w);
	}
	centroidDecomposition (1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}