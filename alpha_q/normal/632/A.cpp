#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, p, A[50];
	cin >> n >> p;
	for (int i = n; i >= 1; i--) {
		string s; cin >> s;
		if (s == "half") A[i] = 0;
		else A[i] = 1;
	}
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i]) tot += tot + 1;
		else tot += tot;
	}
	
	long long sum = 0;
	while (tot) {
		if (tot % 2 == 0) {
			tot /= 2;
			sum += p * tot;
		} else {
			sum += tot * p/2;
			tot /= 2;
		}
	}
	cout << sum << endl;
	return 0;
}