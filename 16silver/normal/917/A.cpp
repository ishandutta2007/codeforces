#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char c[5050];

int main()
{
	int i, j, n, lo, hi, ans = 0;
	scanf("%s", c);
	n = strlen(c);
	for (i = 0; i < n; i++) {
		lo = 0;
		hi = 0;
		for (j = i; j < n; j++) {
			if (c[j] == '(') {
				lo++;
				hi++;
			}
			else if (c[j] == ')') {
				if (lo == 0) lo = 1;
				else lo--;
				if (hi == 0) break;
				else hi--;
			}
			else {
				if (lo == 0) lo = 1;
				else lo--;
				hi++;
			}
			if (lo == 0) ans++;
		}
	}
	printf("%d", ans);
    return 0;
}