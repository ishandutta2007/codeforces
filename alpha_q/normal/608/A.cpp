#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, s, f, t, tim = 0; cin >> n >> s;
	int A[1005]; memset(A, 0, sizeof A);
	for (int i = 0; i < n; i++) {
		cin >> f >> t;
		A[f] = max(A[f], t);
	}
	for (int i = s; i >= 1; i--) {
		tim = max(tim, A[i]);
		tim++;
	}
	cout << tim << endl;
	return 0;
}