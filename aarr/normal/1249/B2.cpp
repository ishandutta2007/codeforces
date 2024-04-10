#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;

int mark[N];
int ans[N];
int a[N];
int main() {
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (int j = 1; j <= n; j++) {
			if (mark[j] != i) {
				int sz = 0, x = j;
				while (sz == 0 || x != j) {
					mark[x] = i;
					x = a[x];
					sz++;
				}
				ans[j] = sz;
				x = a[x];
				while (x != j) {
					ans[x] = sz;
					x = a[x];
				}
			}
			cout << ans[j] << " ";
		}
		cout << endl;
	}
	return 0;
}