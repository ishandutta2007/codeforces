#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (N == 1) {
		cout << "YES" << endl;
		return 0;
	}
	bool f1 = false;
	bool f2 = false;
	for (int i = 1; i < N; i++) {
		if ((f1||f2) && A[i - 1] < A[i]) {
			cout << "NO" << endl;
			return 0;
		}
		if (f2 && A[i - 1] <= A[i]) {
			cout << "NO" << endl;
			return 0;
		}
		if (A[i - 1] == A[i]) {
			f1 = true;
		}
		if (A[i - 1] > A[i]) {
			f2 = true;
			f1 = true;
		}
	}
	cout << "YES" << endl;
	return 0;
	
}