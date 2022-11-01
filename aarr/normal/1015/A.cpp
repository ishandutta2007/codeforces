#include <iostream>
using namespace std;

const int N = 105;

bool mark[N];

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l;
		cin >> r;
		for (int j = l; j <= r; j++) {
			mark[j] = true;
		}
	}
	int x = 0;
	for (int i = 1; i <= m; i++) {
		if (!mark[i])
			x++;
	}
	cout << x << endl;
	for (int i = 1; i <= m; i++) {
		if (!mark[i])
			cout << i << " ";
	}
	return 0;
}