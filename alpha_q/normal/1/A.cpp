#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m, a; cin >> n >> m >> a;
	long long p = ceil((n * 1.0)/a);
	long long q = ceil((m * 1.0)/a);
	cout << p * q << endl;
	return 0;
}