#include <iostream>
#include <queue>
#include <stack>
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
const int maxn = 1e3 + 2;
const int mod = 1e9 + 9;
const int inf = (1 << 30);
const int block = 316;
const int Del = 12157;
const ll Inf = 1e18;

int n, m, a[maxn][maxn];
bool b[maxn][maxn], mark[maxn][maxn];

vector <int> v[maxn];

bool check (int x) {
	memset (mark, 0, sizeof mark);
	for (int i = 1; i <= n; i++)
		v[i].clear();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] = (a[i][j] >= x);
			if (b[i][j] == 1)
				v[i].PB (j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				if (mark[v[i][j]][v[i][k]])
					return 1;
				mark[v[i][j]][v[i][k]] = 1;
			}
		}
	}
	return 0;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	int lo = 0, hi = 1000 * 1000 * 1000 + 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (check (mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}