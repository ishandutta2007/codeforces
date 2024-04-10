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
const int maxn = 2e5 + 5;
const int mod = 1e9 + 9;
const int inf = (1 << 30);
const int block = 316;
const int Del = 12157;
const ll Inf = 1e18;

int par[maxn], a[maxn], c[maxn];

int n;

int get (int u) {
	if (a[u] < c[u] or u == n + 1)
		return u;
	return par[u] = get (par[u]);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		par[i] = i + 1;
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int p, x;
			cin >> p >> x;
			while (x != 0 and p != n + 1) {
				if (c[p] - a[p] >= x) {
					a[p] += x;
					x = 0;
				}
				else {
					int k = c[p] - a[p];
					a[p] = c[p];
					x -= k;
					p = get (p);
				}
			}
		}
		else {
			int p;
			cin >> p;
			cout << a[p] << '\n';
		}
	}
}