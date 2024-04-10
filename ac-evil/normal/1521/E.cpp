#include <bits/stdc++.h>
using std::vector;
const int L = 1005;
int T, n, m, k, a[L][L];
struct Node { int x, y; };
vector<Node> vec;
void move(int &x, int &y) {
	if (x == -1) return;
	if (x & 1) {
		if (y & 1) {
			if (x + 2 > n) {
				if (y + 2 > n) y = 1, x = 2;
				else y += 2, x = 1;
			} else x += 2;
		} else {
			if (x + 2 > n) {
				if (y + 2 > n) y = 1, x = 1;
				else y += 2, x = 1;
			} else x += 2;
		}
	} else {
		if (x + 2 > n) {
			if (y + 2 > n) x = -1;
			else y += 2, x = 2;
		} else x += 2;
	}
}
bool check() {
	int x = 1, y = 2;
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= n; j++)
	        a[i][j] = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 1; j <= vec[i].y; j++) {
			if (x == -1) return false;
			a[x][y] = vec[i].x;
			move(x, y);
		}
	}
	#define In(x, y) (x > 0 && x <= n && y > 0 && y <= n)
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] && (In(i - 1, j - 1) && a[i][j] == a[i - 1][j - 1] || In(i - 1, j + 1) && a[i][j] == a[i - 1][j + 1] ||
				In(i + 1, j - 1) && a[i][j] == a[i + 1][j - 1] || In(i + 1, j + 1) && a[i][j] == a[i + 1][j + 1])) return false;
	return true;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &k);
		vec.clear();
		for (int i = 1; i <= k; i++) {
			int x; scanf("%d", &x);
			if (x) vec.push_back({i, x});
		}
		if (m == 1) { printf("1\n%d\n", vec[0].x); continue; }
		std::sort(vec.begin(), vec.end(), [](Node a, Node b) { return a.y > b.y; });
		n = std::max(2, (int)sqrt(m));
		for (;; n++)
			if (check()) break;
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				printf("%d%c", a[i][j], " \n"[j == n]);	
	}
	return 0;
}