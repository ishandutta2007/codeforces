#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
	string A; cin >> A;
	int n = A.size(); bool f = 0;
	
	string R = "";
	for (int i = 0; i < n; i++) {
		if (!f && A[i] == '0') {
			f = 1;
		}
		else R += A[i];
	}
	if (R.size() == n) R.erase(R.begin());
	cout << R << endl;
	return 0;
}