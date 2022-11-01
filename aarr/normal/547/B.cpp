#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int l[N];
int r[N];
int ans[N];
pair <int, int> b[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = {a[i], i};
	//	l[i] = i + 1;
	//	r[i] = i - 1;
	}
	sort(b + 1, b + n + 1);
	for (int i = n; i > 0; i--) {
		int x = b[i].second;
		
		int y = x, z = x;
		if (l[x - 1] != 0) {
			y = l[x - 1];
		}
		if (r[x + 1] != 0) {
			z = r[x + 1];
		}
		r[y] = z;
		l[z] = y;
		ans[z - y + 1] = max(ans[z - y + 1], a[x]);
	//	cout << x << " " << y << " " << z << endl;
	}
	for (int i = n; i > 0; i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}