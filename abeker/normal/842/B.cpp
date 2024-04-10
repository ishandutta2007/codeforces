#include <cstdio>
using namespace std;

int main() {
	int r, d, N;
	scanf("%d%d%d", &r, &d, &N);

	int sol = 0;	
	while (N--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		sol += (r - d + z) * (r - d + z) <= x * x + y * y && x * x + y * y <= (r - z) * (r - z);
	}
	
	printf("%d\n", sol);
	
	return 0;
}