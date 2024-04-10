#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int main() {
	long long A[N], n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort (A + 1, A + 1 + n);
	
	long long sum = 0;
	for (int i = 1; i < n; i++) sum += (A[i] * (i + 1));
	cout << (sum + n * A[n]) << endl;
	return 0;
}