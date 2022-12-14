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
const int maxn = 4e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 317;
const int del = 10501;

int n, m;

bool visited[maxn];

vector <int> in[maxn], out[maxn], tpl;

void dfs (int u) {
	visited[u] = 1;
	for (auto w : out[u])
		if (!visited[w])
			dfs (w);
	tpl.PB (u);
}

int c[maxn];

int tmp = 1;

void DFS (int u) {
	visited[u] = 1;
	c[u] = tmp;
	for (auto w : in[u])
		if (!visited[w])
			DFS (w);
}

void scc () {
	for (int i = 2; i <= 2 * m + 1; i++)
		if (!visited[i])
			dfs (i);
	memset (visited, 0, sizeof visited);
	for (int j = 2 * m - 1; j >= 0; j--) {
		if (!visited[tpl[j]])
			DFS (tpl[j]);
		tmp ++;
	}
}

bool twosat () {
	scc ();
	for (int i = 1; i <= m; i++) {
		if (c[2 * i + 0] == c[2 * i + 1])
			return 0;
	}
	return 1;
}	

void addEdge (int fi, int se) {
	out[fi].PB (se ^ 1);
	in[se ^ 1].PB (fi);
	out[se].PB (fi ^ 1);
	in[fi ^ 1].PB (se);
}

int k[maxn];
map <int, int> x[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= min (k[i], k[i + 1]); j++) {
			if (x[i][j] != x[i + 1][j]) {
				if (x[i][j] > x[i + 1][j]) { // (1, 0) --> (x, !fi) - (x, fi) - (!x, !fi)
					int fi = x[i][j], se = x[i + 1][j];
					addEdge (2 * fi + 0, 2 * se + 1);
					addEdge (2 * fi + 0, 2 * se + 0);
					addEdge (2 * fi + 1, 2 * se + 1);
				}
				else { // (0, 0) or (1, 1) or (1, 0) --> (x, !fi)
					int fi = x[i][j], se = x[i + 1][j];
					addEdge (2 * fi + 0, 2 * se + 1);
				}
				break;
			}
			if (j == min (k[i], k[i + 1]))
				if (k[i] > k[i + 1])
					return cout << "No" << endl, 0;
		}
	}

	if (!twosat())
		return cout << "No" << endl, 0;

	cout << "Yes" << endl;
	int cnt = 0;
	for (int i = 1; i <= m; i++) 
		if (c[2 * i + 0] < c[2 * i + 1])
			cnt ++;
	cout << cnt << endl;
	for (int i = 1; i <= m; i++)
		if (c[2 * i + 0] < c[2 * i + 1])
			cout << i << " ";
	cout << endl;
	return 0;
}