#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 100;
const int radikal = 400;

int cnt, n;

int a[maxn];

vector <int> v[maxn];
int dp[radikal][maxn];

int get (int l, int r, int k) {
	int tmp = 0;
	int ret = 0;
	for (int i = 1; i <= cnt; i++) {
		if (tmp >= l and tmp + v[i].size() <= r) {
			ret += dp[i][k];
			tmp += v[i].size();
		}
		else if (tmp < r or tmp + v[i].size() >= l) {
			for (auto w : v[i]) {
				tmp ++;
				if (tmp >= l and tmp <= r)
					ret += (w == k);
			}
		}
		else 
			tmp += v[i].size();
	}
	return ret;
}

int del (int x, int idx) {
	for (int i = idx; i < int (v[x].size()) - 1; i++)
		swap (v[x][i], v[x][i + 1]);
	int k = v[x].back();
	v[x].pop_back();
	dp[x][k] --;
	return k;
}

void add (int x, int idx, int val) {
	vector <int> g;
	for (int i = 0; i < idx; i++)
		g.PB (v[x][i]);
	g.PB (val);
	for (int i = idx; i < v[x].size(); i++)
		g.PB (v[x][i]);
	v[x] = g;
	dp[x][val] ++;
}

void shift (int l, int r) {
	int tmp = 0;
	int m;
	for (int i = 1; i <= cnt; i++) {
		if (tmp + v[i].size() >= r) {
			m = del (i, r - tmp - 1);
			break;
		}
		tmp += v[i].size();
	}
	tmp = 0;
	for (int i = 1; i <= cnt; i++) {
		if (tmp + v[i].size() >= l) {
			add (i, l - tmp - 1, m);
			break;
		}
		tmp += v[i].size();
	}
}

void refresh () {
	int tmp = 1;
	for (int i = 1; i <= cnt; i++) {
		for (auto w : v[i]) {
			dp[i][w] --;
			a[tmp ++] = w;
		}
		v[i].clear();
	}
	cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (v[cnt].size() == radikal)
			cnt ++;
		v[cnt].PB (a[i]);
		dp[cnt][a[i]] ++;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	refresh ();
	int lastans = 0;
	for (int i = 1; i <= m; i++) {
		if (i % radikal == 0)
			refresh ();
		int type, l, r, x;
		cin >> type >> l >> r;
		l = ((l + lastans - 1) % n) + 1, r = ((r + lastans - 1) % n) + 1;
		if (l > r)
			swap (l, r);
		//		cout << l << " " << r << endl;
		if (type == 1) 
			shift (l, r);
		else {
			cin >> x;
			x = ((x + lastans - 1) % n) + 1;
			lastans = get (l, r, x);
			cout << lastans << endl;
		}
		//		for (auto w : v[1])
		//			cout << w << " - ";
		//		cout << endl;
	}
}