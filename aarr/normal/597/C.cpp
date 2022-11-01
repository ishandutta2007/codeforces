#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, K = 12;
int n, k;

long long s[4 * N][K];
int a[N];

void update(int i, long long x, int j, int id = 1, int L = 0, int R = n) {
	if (i < L || R <= i)
		return ;
	if (R - L == 1) {
		s[id][j] += x;
		return ;
	}
	int md = (L + R) / 2;
	update(i, x, j, id * 2, L, md);
	update(i, x, j, id * 2 + 1, md, R);
	s[id][j] = s[id * 2][j] + s[id * 2 + 1][j];
}
long long get(int l, int r, int j, int id = 1, int L = 0, int R = n) {
	if (r <= L || R <= l)
		return 0;
	if (l <= L && R <= r) {
		return s[id][j];
	}
	long long ans = 0;
	int md = (L + R) / 2;
	ans += get(l, r, j, id * 2, L, md);
	ans += get(l, r, j, id * 2 + 1, md, R);
	return ans;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		update(a[i], 1, 1);
//		cout << 73 << endl;
		for (int j = 2; j <= k + 1; j++) {
			long long x = get(0, a[i], j - 1);
			update(a[i], x, j);
		}
	}
	cout << get(0, n, k + 1) << endl;
	return 0;
}