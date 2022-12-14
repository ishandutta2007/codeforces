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
const int maxn = 2500 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 317;
const ll Inf = 1e18;
const int del = 10501;

bool cutver = 0;

bool visited[maxn];

int h[maxn], bck[maxn];

vector <int> v[maxn];

void dfs (int u) {
	if (u != 1)
		bck[u] = h[u] - 1;
	visited[u] = 1;
	int cnt = 0;
	for (auto w : v[u]) {
		if (!visited[w]) {
			h[w] = h[u] + 1;
			dfs (w);
			if (u != 1 and bck[w] >= h[u]) {
				cutver = 1;
			}
			bck[u] = min (bck[w], bck[u]);
			cnt ++;
			
		}
		else
			bck[u] = min (bck[u], h[w]);
	}
	if (u == 1 and cnt >= 2)
		cutver = 1;
}

int n, m;

bool ok (int fi, int se) {
	return fi < n and fi >= 0 and se < m and se >= 0;
}

int x[] = {-1, 0, 1, 0};
int y[] = {0, -1, 0, 1};

int id[maxn][maxn];

string s[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#')
				cnt ++;
	if (cnt <= 2)
		return cout << -1 << endl, 0;
	int tmp = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { 
			if (s[i][j] == '#') {
				id[i][j] = tmp ++;
				for (int k = 0; k < 2; k++) { 
					if (ok (i + x[k], j + y[k]) and s[i + x[k]][j + y[k]] == '#') {
						int fi = id[i][j], se = id[i + x[k]][j + y[k]];
						v[fi].PB (se);
						v[se].PB (fi);
					}
				}
			}
		}
	}
	
	dfs (1);
	cout << 2 - cutver << endl;
}