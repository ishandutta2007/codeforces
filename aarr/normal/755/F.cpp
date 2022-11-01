#include <iostream>
#include <bitset>
using namespace std;

const int N = 1000 * 1000 + 5;

int a[N];
bool mark[N];
bitset<N> mk;
int b[2 * N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int oc = 0;
	for (int i = 1; i <= n; i++) {
		int v = i;
		int x = 0;
		while (!mark[v]) {
			mark[v] = true;
			v = a[v];
			x++;
		}
		b[x]++;
		oc += x % 2;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] % 2 == 1) {
			b[i * 2] += b[i] / 2;
			b[i] = 1;
		}
		else if (b[i] > 0) {
			b[i * 2] += b[i] / 2 - 1;
			b[i] = 2;
		}
	}
	mk[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < b[i]; j++) {
			mk |= mk << i;
		}
	}
	int x = (n - oc) / 2;
	if (mk[k]) {
		cout << k << " ";
	}
	else {
		cout << k + 1 << " ";
	}
	if (k <= x) {
		cout << 2 * k;
	}
	else {
		cout << min(n, k + x);
	}
	return 0;
}