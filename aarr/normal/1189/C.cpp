#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int ps[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l;
		cin >> r;
		int x = ps[r] - ps[l - 1];
		cout << x / 10 << endl;
	}
	return 0;
}