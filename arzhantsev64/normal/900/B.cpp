#include <bits/stdc++.h>

using namespace std;

int main() {
	int p, q, c;
	cin >> p >> q >> c;
	set<int> was;
	int num = 0;
	while (1) {
		num++;
		p *= 10;
		if (was.count(p)) {
			cout << -1 << endl;
			break;
		}
		was.insert(p);
		if (p / q == c) {
			cout << num << endl;
			break;
		}
		p %= q;
	}
}