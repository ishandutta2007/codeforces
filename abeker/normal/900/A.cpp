#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int pos = 0, neg = 0;
	while (N--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > 0)
			pos++;
		else
			neg++;
	}
	puts(pos > 1 && neg > 1 ? "No" : "Yes");
	return 0;
}