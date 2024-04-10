#include <bits/stdc++.h>

using namespace std;

int A[10], B[10];

int main() {
	for (int i = 1; i <= 6; i++) cin >> A[i];
	cout << (A[1] + A[2] + A[3]) * (A[1] + A[2] + A[3]) - A[1] * A[1] - A[3] * A[3] - A[5] * A[5];
	return 0;
}