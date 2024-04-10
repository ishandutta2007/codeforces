#include "bits/stdc++.h"
using namespace std;

int main() {
	int x; int y;
	while (~scanf("%d%d", &x, &y)) {
		int ans;
		bool swapped = false;
		if (x > y) swap(x, y), swapped = true;
		if (x == y || (x == 2 && y == 4)) {
			ans = 0;
		} else if (x == 1 || (x == 2 && y == 3)) {
			ans = -1;
		} else {
			ans = 1;
		}
		if (swapped) ans = -ans;
		printf("%c\n", "<=>"[ans + 1]);
	}
}