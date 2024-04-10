#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int spec = 3;
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x == spec) {
			puts("NO");
			return 0;
		}
		spec = 6 - x - spec;
	}
	puts("YES");
	return 0;
}