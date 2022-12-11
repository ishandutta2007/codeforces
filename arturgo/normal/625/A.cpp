#include <iostream>
using namespace std;

int main() {
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	
	if(a <= b - c || b > n)
		cout << n / a;
	else {
		long long deb = 1 + (n - b) / (b - c);
		n -= deb * (b - c);
		cout << deb + n / a;
	}
	return 0;
}