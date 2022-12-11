#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long f(int n) {
	if(n == 0)
		return 1;
	return n * f(n - 1);
}

int main() {
	int k;
	cin >> k;
	
	cout << (f(2*k - 2) / f(k - 1) / f(k - 1)) << endl;
}