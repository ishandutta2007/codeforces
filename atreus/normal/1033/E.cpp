#include <iostream>
#include <queue>
#include <bitset>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
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

const int maxn = 1000 + 100;
const int mod = 998244353;

vector <int> v, last, last2;
int height = 1;

vector <int> g[maxn];

int h[maxn];

int ask_last () {
	int m;
	cout << "? " << g[height].size() << endl;
	for (auto w : g[height])
		cout << w << " ";
	cout << endl;
	cin >> m;
	return m;
}

int ask (int lo, int hi) {
	int m, q;
	cout << "? " << hi - lo << endl;
	for (int i = lo; i < hi; i++)
		cout << v[i] << " ";
	cout << endl;
	cin >> m;
	cout << "? " << hi - lo + g[height - 1].size() << endl;
	for (int i = lo; i < hi; i++)
		cout << v[i] << " ";
	for (auto w : g[height - 1])
		cout << w << " ";
	cout << endl;
	cin >> q;
	return q - m;
}

void find (int lo, int hi) {
	int q = ask (lo, hi);
	if (q == 0)
		return;
	if (lo + 1 == hi) {
		g[height].PB (v[lo]);
		h[v[lo]] = height;
		return;
	}
	int mid = (hi + lo) >> 1;
	find (lo, mid);
	find (mid, hi);
}

int question (int x) {
	cout << "? " << (int)g[height].size() - x << endl;
	for (int i = x; i < g[height].size(); i++)
		cout << g[height][i] << " ";
	cout << endl;
	int m;
	cin >> m;
	cout << "? " << (int)g[height].size() - x - 1 << endl;
	for (int i = x + 1; i < g[height].size(); i++)
		cout << g[height][i] << " ";
	cout << endl;
	int q;
	cin >> q;
	return m - q;
}

bool has_edge (int fi, int se) {
	cout << "? 2" << endl;
	cout << fi << " " << se << endl;
	int m;
	cin >> m;
	return m > 0;
}

void find_cycle () {
	int idx = -1, fi, se;
	for (int i = 0; i < g[height].size(); i++) {
		if (question (i) > 0) {
			fi = g[height][i];
			idx = i;
			break;
		}
	}
	for (int i = idx + 1; i < g[height].size(); i++) {
		int u = g[height][i];
		if (has_edge (u, fi)) {
			se = u;
			break;
		}
	}
	vector <int> c1, c2;
	c1.PB (fi);
	c2.PB (se);
	while (fi != se) {
		height --;
		for (auto w : g[height]) {
			if (has_edge (fi, w)) {
				c1.PB (w);
				fi = w;
				break;
			}
		}
		for (auto w : g[height]) {
			if (has_edge (se, w)) {
				c2.PB (w);
				se = w;
				break;
			}
		}
	}
	cout << "N " << c1.size() + c2.size() - 1 << endl;
	for (int i = 0; i < c1.size(); i++)
		cout << c1[i] << " ";
	for (int i = (int)(c2.size()) - 2; i >= 0; i--)
		cout << c2[i] << " ";
	cout << endl;
}

int main (){
	ios_base::sync_with_stdio (false);
	memset (h, -1, sizeof h);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
		v.PB (i);
	g[0].PB (n);
	h[n] = 0;
	while (!v.empty()) {
		find (0, v.size());
		v.clear();
		for (int i = 1; i <= n; i++)
			if (h[i] == -1)
				v.PB (i);

		if (ask_last () != 0) {
			find_cycle ();
			return 0;
		}
		height ++;
	}
	cout << "Y ";
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (h[i] % 2 == 0)
			cnt ++;
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (h[i] % 2 == 0)
			cout << i << " ";
	cout << endl;
}