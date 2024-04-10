#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

const int INF = 1e9;
const int MAXN = 1000000;

struct Node {
	int pr = 0;
	int min = 0;
	int max = 0;
};

int n;
int s;
Node a[MAXN];

void push(int v, int lf, int rg) {
	a[v].max += a[v].pr;
	a[v].min += a[v].pr;
	if (rg - lf > 1) {
		a[2 * v + 1].pr += a[v].pr;
		a[2 * v + 2].pr += a[v].pr;
	}	
	a[v].pr = 0;
}

void relax(int v, int lf, int rg) {
	a[v].min = min(a[2 * v + 1].min, a[2 * v + 2].min);
	a[v].max = max(a[2 * v + 1].max, a[2 * v + 2].max);
}

void add(int v, int lf, int rg, int l, int r, int val) {
	if (r <= lf || rg <= l)
		return;

	if (l <= lf && rg <= r) {
		a[v].pr += val;
		return;
	}
	push(v, lf, rg);

	int mid = (lf + rg) / 2;
	add(2 * v + 1, lf, mid, l, r, val);
	add(2 * v + 2, mid, rg, l, r, val);

	push(2 * v + 1, lf, mid);
	push(2 * v + 2, mid, rg);
	relax(v, lf, rg);
}

int get(int v, int lf, int rg, int pos) {
	push(v, lf, rg);
	if (rg - lf == 1)
		return a[v].min;
	int mid = (lf + rg) / 2;
	if (pos < mid)
		return get(2 * v + 1, lf, mid, pos);
	return get(2 * v + 2, mid, rg, pos);
}

int getLeftest(int v, int lf, int rg, int val) {
 	push(v, lf, rg);
 	// cout << "!" << v << " " << a[v].min << " " << a[v].max << " " << val << endl;
	if (a[v].min > val || a[v].max < val)
		return -1;

	if (rg - lf == 1)  
		return lf;

	int mid = (lf + rg) / 2;
	int x = getLeftest(2 * v + 2, mid, rg, val);
	if (x != -1)
		return x;
	return getLeftest(2 * v + 1, lf, mid, val);
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;

	vector<int> b(n);

	for (int i = 0; i < n; ++i) {
		int p;
		--p;
		int type;
		cin >> p >> type;
		--p;
		if (type == 0) {
			add(0, 0, n + 1, p + 1, n + 1, -1);
		} else {
			cin >> b[p];
			add(0, 0, n + 1, p + 1, n + 1, 1);
		}

		int x = get(0, 0, n + 1, n);
		// cout << x - 1 << endl;

		int pos = getLeftest(0, 0, n + 1, x - 1);
		// cout << pos << endl;

		if (pos <= -1) {
			cout << -1 << endl;
		} else {
			cout << b[pos] << endl;
		}
	}
	return 0;
}