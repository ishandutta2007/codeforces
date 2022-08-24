#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, sx, sy, cc;
char p[120][120];
int main() {
	int i, j;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
		for (j = 1; j <= m; j++) {
			if (p[i][j] == 'B') {
				sx += i, sy += j;
				cc++;
			}
		}
	}
	printf("%d %d\n", sx / cc, sy / cc);
}