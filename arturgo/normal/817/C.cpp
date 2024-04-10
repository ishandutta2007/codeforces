#include <iostream>
#include <algorithm>
using namespace std;

long long sumD(long long nb) {
	long long sum = 0;
	while(nb != 0) {
		sum += (nb % 10);
		nb /= 10;
	}
	return sum;
}

int main() {
	long long n, s;
	cin >> n >> s;
	
	long long deb = 0, fin = n + 1;
	while(fin - deb > 1) {
		long long mil = (deb + fin) / 2;
		
		if(mil - sumD(mil) >= s) {
			fin = mil;
		}
		else {
			deb = mil;
		}
	}
	
	cout << (n + 1 - (deb + 1)) << endl;
}