
#include <iostream>
#include <algorithm>
#include <cstring>

long long A, B, K;
const int SIZE = 3000005;
bool comp[SIZE];
long long pCount[SIZE];

bool isPrime(int x) { return x < 2 ? false : !comp[x]; }
int primesBtw(int i, int j) { return pCount[std::max(j, 0)] - pCount[std::max(i - 1, 0)]; }

bool check(int l) {
	for (int x = A; x <= B - l + 1; ++x) {
		if (primesBtw(x, x + l - 1) < K)
			return false;
	}
	return true;
}

int program() {
	// sieve
	for (int i = 2; i*i < SIZE; ++i) {
		if (!comp[i]) {
			for (int j = i*i; j < SIZE; j += i) {
				comp[j] = true;
			}
		}
	}

	// prime count
	for (int i = 2; i < SIZE; ++i)
		pCount[i] = pCount[i - 1] + (isPrime(i) ? 1 : 0);

	std::cin >> A >> B >> K;

	// binary search
	int low = 1;
	int high = B - A + 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	return check(low) ? low : -1;
}

int main() {
	std::cout << program();
	return 0;
}