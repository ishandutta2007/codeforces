#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m, k;
set<int> sr[N], sc[N], tr, tc;
map<int, map<int, int> > mp;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) sr[i].insert(0), sr[i].insert(m + 1);
	for (int j = 1; j <= m; j++) sc[j].insert(0), sc[j].insert(n + 1);
	tr.insert(0), tr.insert(m + 1);
	tc.insert(0), tc.insert(n + 1);
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		sr[x].insert(y);
		sc[y].insert(x);
	}
	int x = 1, y = 1, d = 0;
	long long sum = 0;
	while (true) {
		mp[x][y]++;
		if (mp[x][y] >= 2) break;
		if (d == 0) {
			int ny = min((*sr[x].upper_bound(y)) - 1, (*tr.upper_bound(y)) - 1);
			tc.insert(x);
			sum += abs(y - ny);
			y = ny;
		} else if (d == 1) {
			int nx = min((*sc[y].upper_bound(x)) - 1, (*tc.upper_bound(x)) - 1);
			tr.insert(y);
			sum += abs(x - nx);
			x = nx;
		} else if (d == 2) {
			int ny = max((*(--sr[x].lower_bound(y))) + 1, (*(--tr.lower_bound(y))) + 1);
			tc.insert(x);
			sum += abs(y - ny);
			y = ny;
		} else {
			int nx = max((*(--sc[y].lower_bound(x))) + 1, (*(--tc.lower_bound(x))) + 1);
			tr.insert(y);
			sum += abs(x - nx);
			x = nx;
		}
		d = (d + 1) % 4;
	}
	sum++;
	sum = 1ll * n * m - sum;
	if (sum == k) {puts("Yes"); return 0;}
	tr.clear();
	tc.clear();
	x = 1, y = 1, d = 1;
	sum = 0;
	mp.clear();
	tr.insert(0), tr.insert(m + 1);
	tc.insert(0), tc.insert(n + 1);
	while (true) {
		mp[x][y]++;
		if (mp[x][y] >= 2) break;
		if (d == 0) {
			int ny = min((*sr[x].upper_bound(y)) - 1, (*tr.upper_bound(y)) - 1);
			tc.insert(x);
			sum += abs(y - ny);
			y = ny;
		} else if (d == 1) {
			int nx = min((*sc[y].upper_bound(x)) - 1, (*tc.upper_bound(x)) - 1);
			tr.insert(y);
			sum += abs(x - nx);
			x = nx;
		} else if (d == 2) {
			int ny = max((*(--sr[x].lower_bound(y))) + 1, (*(--tr.lower_bound(y))) + 1);
			tc.insert(x);
			sum += abs(y - ny);
			y = ny;
		} else {
			int nx = max((*(--sc[y].lower_bound(x))) + 1, (*(--tc.lower_bound(x))) + 1);
			tr.insert(y);
			sum += abs(x - nx);
			x = nx;
		}
		d = (d + 1) % 4;
	}
	sum++;
	sum = 1ll * n * m - sum;
	if (sum == k) {puts("Yes"); return 0;}
	puts("No");
	return 0;
}