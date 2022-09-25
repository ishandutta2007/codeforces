#include <bits/stdc++.h>

using namespace std;

const int MX = 3000;

bool isPrime[MX];

int main() {
	fill(isPrime, isPrime + MX, true);
	for (int i = 2; i < MX; i++)
		for (int j = 2 * i; j < MX; j += i)
			isPrime[j] = false;
	
	int n;
	ignore = scanf("%d", &n);
	
	vector<pair<int, int>> E;
	for (int i = 1; i < n; i++) E.emplace_back(i, i + 1);
	E.emplace_back(n, 1);
	
	int k = 0;
	while (isPrime[E.size() + k] == false) k++;
	
	assert(2 * k <= n);
	
	for (int i = 0; i < k; i++) {
		E.emplace_back(1 + i, 1 + n / 2 + i);
	}
	
	printf("%d\n", (int)E.size());
	for (auto& e : E) {
		printf("%d %d\n", e.first, e.second);
	}
	
	return 0;
}