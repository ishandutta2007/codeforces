#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5;
int n;
int lnd;

int a[N];
int mn[4 * N];
int mx[4 * N];
int lazy[4 * N];

void div(int id) {
	lazy[id * 2] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];
	lazy[id] = 0;
}
void update(int l, int r, int x, int id = 1, int L = 0, int R = n) {
	if (l <= L && R <= r) {
		lazy[id] += x;
		if (L == n - 1 && R == n)
			lnd = id;
		return;
	}
	if (R <= l || r <= L)
		return;
	div(id);
	int md = (L + R) / 2;
	update(l, r, x, id * 2, L, md);
	update(l, r, x, id * 2 + 1, md, R);
	mn[id] = min(mn[id * 2] + lazy[id * 2], mn[id * 2 + 1] + lazy[id * 2 + 1]);
	mx[id] = max(mx[id * 2] + lazy[id * 2], mx[id * 2 + 1] + lazy[id * 2 + 1]);
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == 'L')
			p--;
		if (c == 'R')
			p++;
		if (p < 0)
			p = 0;
		if (c != 'L' && c != 'R') {
			update(p, n, -a[p]);
			a[p] = 0;
		}
		if (c == '(') {
			update(p, n, 1);
			a[p] = 1;
		}
		if (c == ')') {
			update(p, n, -1);
			a[p] = -1;
		}
		update(n - 1, n, 0);
		int x = mn[1], y = mx[1];
		x += lazy[1], y += lazy[1];
	//	cout << "73 " << lnd << endl;
		if (x < 0 || lazy[lnd] != 0) {
			cout << -1 << " ";
		}
		else {
			cout << y << " ";
		}
	}
	return 0;
}