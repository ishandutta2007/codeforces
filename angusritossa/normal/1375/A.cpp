#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int done[110][110][2], n, val[110], upto;
int flipped[110], foundans;
void dp(int a, int b, int pre) {
	if (foundans == upto) return;
	if (done[a][b][pre] == upto) return;
	done[a][b][pre] = upto;
	if (a == n) {
		if (b == n/2) {
			for (int i = 0; i < n; i++) {
				if (flipped[i]) printf("%d ", -val[i]);
				else printf("%d ", val[i]);
			}
			printf("\n");
			foundans = upto;
		}
		return;
	}
	if (!a) dp(a+1, b, 0), dp(a+1, b, 1);
	else {
		int other = val[a-1];
		if (pre) other *= -1;
		if (val[a] >= other) dp(a+1, b+1, 0);
		if (val[a] <= other) dp(a+1, b, 0);
		flipped[a] = 1;
		if (-val[a] >= other) dp(a+1, b+1, 1);
		if (-val[a] <= other) dp(a+1, b, 1);
		flipped[a] = 0;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &val[i]);
			flipped[i] = 0;
		}
		upto++;
		dp(0, 0, 0);
	}
}