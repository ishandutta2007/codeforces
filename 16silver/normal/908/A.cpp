#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, i, r = 0;
	char c[100];
	scanf("%s", c);
	n = strlen(c);
	for (i = 0; i < n; i++) {
		if (c[i] >= '0' && c[i] <= '9') {
			if ((c[i] - '0') % 2 == 1) r++;
		}
		else {
			if (c[i] == 'a' || c[i] == 'e' || c[i] == 'o' || c[i] == 'u' || c[i] == 'i') r++;
		}
	}
	printf("%d", r);
}