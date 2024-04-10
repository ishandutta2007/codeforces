#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int sq = 500;

int com;

set <int> s;

int nxt[maxn], pre[maxn];

int ind = 0;
int c[maxn], l[maxn], r[maxn];

unordered_map <int, int> mp[maxn];

bool visited[maxn];

int n, m;

void bfs (int u) {
	queue <int> q;
	q.push (u);
	pre[nxt[u]] = pre[u];
	nxt[pre[u]] = nxt[u];
	l[com] = ind;
	while (!q.empty()) {
		int tmp = nxt[0], v = q.front();
		q.pop();
		visited[v] = 1;
		c[ind ++] = v;

		while (tmp != n + 1) {
			if (!mp[v].count (tmp)) {
				nxt[pre[tmp]] = nxt[tmp];
				pre[nxt[tmp]] = pre[tmp];
				q.push (tmp);
			}
			tmp = nxt[tmp];
		}
	}
	r[com] = ind;
}

int main() {	
	ios_base::sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		mp[v][u] = 1;
		mp[u][v] = 1;
	}
	
	for (int i = 0; i <= n; i++)
		nxt[i] = i + 1;
	for (int i = 1; i <= n; i++)
		pre[i] = i - 1;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs (i);
			com ++;
		}
	}
	
	cout << com << endl;
	for (int i = 0; i < com; i++) {
		cout << r[i] - l[i] << " ";
		for (int j = l[i]; j < r[i]; j++)
			cout << c[j] << " ";
		cout << endl;
	}
	return 0;
}