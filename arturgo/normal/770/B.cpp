#include <iostream>
using namespace std;

int s(long long n) {
	int r = 0;
	while(n != 0) {
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main() {
	long long n;
	cin >> n;
	
	long long p10 = 1;
	int m = s(n);
	long long a = n;
	while(n != 0) {
		if(m < s(n * p10 - 1)) {
			m = s(n * p10 - 1);
			a = n * p10 - 1;
		}
		
		n /= 10;
		p10 *= 10;
	}
	
	cout << a << endl;
}