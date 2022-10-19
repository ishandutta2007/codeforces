#include <cstdio>
using namespace std;

int main() {
	int N, T, K, D;
	scanf("%d%d%d%d", &N, &T, &K, &D);
	int sol = ((N - 1) / K + 1) * T;
	int lo = D, hi = 1000000;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (mid / T * K + (mid - D) / T * K >= N)
			hi = mid;
		else
			lo = mid + 1;
	}
	
	puts(lo < sol ? "YES" : "NO");
	
	return 0;
}