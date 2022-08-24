#include<cstdio>
#include<algorithm>
using namespace std;
char p[30];
int Query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", p);
	if (p[0] == 'x')return 1;
	return 2;
}
int main() {
	int i;
	while (1) {
		scanf("%s", p);
		if (p[0] !='s')break;
		int t = 1;
		while (Query(t, t * 2) == 2)t *= 2;
		int b = t, e = t * 2, mid, res = 0;
		while (b <= e) {
			mid = (b + e) >> 1;
			if (Query(t - 1, mid) == 1) {
				res = mid;
				e = mid - 1;
			}
			else {
				b = mid + 1;
			}
		}
		printf("! %d\n", res);
		fflush(stdout);
	}
}