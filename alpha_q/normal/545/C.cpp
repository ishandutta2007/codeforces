#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
	pair <int, int> A[N];
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].first >> A[i].second;
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	int Ret = 2, last = A[1].first;
	for (int i = 2; i < n; i++) {
		int x = A[i].first, h = A[i].second;
		if (x - h > last) last = x, ++Ret;
		else if (x + h < A[i + 1].first) last = x + h, ++Ret;
		else last = x;
	}
	
	cout << Ret << endl;
	return 0;
}