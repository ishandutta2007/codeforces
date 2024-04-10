#include <iostream>
using namespace std;

const int N = 150 * 1000;
int n, m;

int a[N];
int ans[4 * N];

void update(int p, int b, int h = n, int id = 1, int L = 0, int R = 1 << n) {
	if (R <= p || p < L)
		return ;
	if (R - L == 1) {
		a[L] = b;
		ans[id] = b;
		return ;
	}
	int md = (L + R) / 2;
	update(p, b, h - 1, id * 2, L, md);
	update(p, b, h - 1, id * 2 + 1, md, R);
	if (h % 2 == 1) {
		ans[id] = ans[id * 2] | ans[id * 2 + 1];
	}
	else {
		ans[id] = ans[id * 2] ^ ans[id * 2 + 1];
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int p, b;
		cin >> p >> b;
		update(p - 1, b);
		cout << ans[1] << endl;
	}
	return 0;
}