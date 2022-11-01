#include <bits/stdc++.h>

using namespace std;

int main() {
	deque <int> A, B;
	int n, k1, k2, m; cin >> n;
	
	cin >> k1;
	for (int i = 0; i < k1; i++) cin >> m, A.push_back(m);
	cin >> k2;
	for (int i = 0; i < k2; i++) cin >> m, B.push_back(m);
	
	int f = 0; m = 10000;
	while (m--) {
		if (A.empty()) {
			cout << f << " 2\n";
			return 0;
		}
		if (B.empty()) {
			cout << f << " 1\n";
			return 0;
		}
		int a = A.front(), b = B.front();
		A.pop_front(), B.pop_front();
		if (a > b) {
			A.push_back(b);
			A.push_back(a);
		} else {
			B.push_back(a);
			B.push_back(b);
		}
		f++;
	}
	cout << "-1\n";
	return 0;
}