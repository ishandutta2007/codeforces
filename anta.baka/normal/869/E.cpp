#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m, q;
int t[2500][2500];
map<pair<pair<int, int>, pair<int, int>>, int> val;

void upd(int ii, int jj, int x) {
	for(int i = ii; i < n; i |= i + 1)
		for(int j = jj; j < m; j |= j + 1)
			t[i][j] += x;
}

int get(int ii, int jj) {
	int ret = 0;
	for(int i = ii; i >= 0; i &= i + 1, i--)
		for(int j = jj; j >= 0; j &= j + 1, j--)
			ret += t[i][j];
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));
	cin >> n >> m >> q;
	while(q--) {
		int type, r1, c1, r2, c2;
		cin >> type >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;
		if(type == 1) {
			int x = rand();
			x *= rand();
			val[{{r1, c1}, {r2, c2}}] = x;
			upd(r1, c1, x);
			upd(r1, c2 + 1, -x);
			upd(r2 + 1, c1, -x);
			upd(r2 + 1, c2 + 1, x);
		} else if(type == 2) {
			int x = val[{{r1, c1}, {r2, c2}}];
			upd(r1, c1, -x);
			upd(r1, c2 + 1, x);
			upd(r2 + 1, c1, x);
			upd(r2 + 1, c2 + 1, -x);
		} else {
			cout << (get(r1, c1) == get(r2, c2) ? "Yes\n" : "No\n");
		}
	}
}