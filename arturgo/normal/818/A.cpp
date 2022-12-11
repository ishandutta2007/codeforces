#include <iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	
	long long c = n / (2 * (1 + k));
	
	cout << c << " " << k * c << " " << n - (1 + k) * c << endl;
}