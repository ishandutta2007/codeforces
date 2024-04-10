#include <bits/stdc++.h>
using namespace std;
long long  factorial(long long A) {
	long long res = 1;
	for (int i = 1; i <= A; i++) {
		res *= i;
	}
	return res;
}
int main() {
	long long A, B;
	cin >> A >> B;
	cout << factorial(min(A,B)) << endl;
	return 0;
	
}