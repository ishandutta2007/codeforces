#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int N;
	scanf("%d", &N);
	int mini = INF, maks = -INF;
	int sum = 0;
	while (N--) {
		int c, d;
		scanf("%d%d", &c, &d);
		if (d == 1) 
			maks = max(maks, 1900 - sum);
		else 
			mini = min(mini, 1899 - sum);
		sum += c;
	}
	if (maks > mini)
		puts("Impossible");
	else if (mini == INF)
		puts("Infinity");
	else 
		printf("%d\n", mini + sum);
	return 0;
}