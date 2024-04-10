#include <cstdio>
using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (!(x % i))
			return false; 
	return true;
}

int solve(int x) {
	if (prime(x))
		return 1;
	if (!(x % 2) || prime(x - 2))
		return 2;
	return 3;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", solve(N));
	return 0;
}