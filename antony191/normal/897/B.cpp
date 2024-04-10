#include <iostream>


using namespace std;

long long len(long long a);
long long power(long long a);
long long turn(long long a);

int main() {
	long long k, p;
	cin >> k; 
	cin >> p;
	long long s = 0;
	for (int i = 1; i <= k; ++i) {
		s += i * power(len(i)) + turn(i);
	}
	cout << s % p;
	return 0;
}

long long len(long long a) {
	int s = 0;
	while (a > 0) {
		a /= 10;
		++s;
	}
	return s;
}

long long power(long long a) {
	long long k = 1;
	while (a > 0) {
		k *= 10;
		--a;
	}
	return k;
}

long long turn(long long a) {
	long long k = 0;
	while (a > 0) {
		k *= 10;
		k += a % 10;
		a /= 10;
	}
	return k;
}