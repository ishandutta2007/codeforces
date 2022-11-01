#include <bits/stdc++.h>

using namespace std;

int leg (int x) {
	int ret = 0;
	while (x) x /= 5, ret += x;
	return ret;
}

vector <int> V; int m, k = 0, i, L;

int main() {
	cin >> m;
	for (i = 1; i <= 400010; i++) {
		L = leg(i);
		if (L > m) break;
		if (L == m) V.push_back(i), k++;
	}
	if (k == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << k << endl;
	for (i = 0; i < k; i++) cout << V[i] << " ";
	cout << endl;
	return 0;
}