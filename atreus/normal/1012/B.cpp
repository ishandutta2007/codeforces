#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
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
const int maxn = 4e5 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

vector <int> v[maxn];
int par[maxn];

bool mark[maxn];

int get (int u) {
	if (par[u] < 0)
		return u;
	return par[u] = get (par[u]);
}

void merge (int u, int w) {
	u = get (u), w = get(w);
	if (u == w)
		return;
	if (par[u] > par[w])
		swap (u, w);
	par[u] += par[w];
	par[w] = u;
}

bool visited[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	memset (par, -1, sizeof par);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		v[y].PB (x);
		visited[x] = 1;
	}
	
	for (int i = 1; i <= m; i++) {
		if (v[i].size() > 1)
			for (int j = 0; j < v[i].size() - 1; j++) 
				merge (v[i][j], v[i][j + 1]);
	}
	
	
	vector <int> ans;
	for (int i = 1; i <= n; i++) {
		int u = get (i);
		if (visited[u] and !mark[u]) {
			ans.PB (u);
			mark[u] = 1;
		}
	}
	int cnt = ans.size() - 1;
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			tot ++;
	int sum = 0;
	for (int i = 1; i <= m; i++)
		if (v[i].empty())
			sum ++;
//	cout << tot << " " << sum << " " << cnt << endl;
	cout << tot + sum + cnt << endl;
}