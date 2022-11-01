#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, A[105], i; cin >> n;
	for (i = 1; i <= n; i++) cin >> A[i];
	sort (A + 1, A + n + 1);
	for (i = 1; i <= n; i++) cout << A[i] << " ";
	return 0;
}