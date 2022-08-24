#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char p[101000], q[101000];
struct point {
	int ck, mask;
}w[101000];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s%s", p, q);
		int mask = 0;
		for (j = 0; q[j]; j++)mask |= (1 << (q[j] - 'a'));
		w[i].mask = mask;
		if (p[0] == '.') w[i].ck = 0;
		else if (p[0] == '?') w[i].ck = 2;
		else w[i].ck = 1;
	}
	int tp = q[0] - 'a';
	int Mx = 0;
	for (i = 0; i < 26; i++) {
		if (tp == i)continue;
		for (j = 1; j < n; j++) {
			if (w[j].ck %2 == 0 && ((w[j].mask >> i) & 1)) {
				break;
			}
			if (w[j].ck == 1 && !((w[j].mask >> i) & 1)) {
				break;
			}
		}
		Mx = max(Mx, j);
	}
	int res = 0;
	for (i = Mx + 1; i < n; i++) {
		if (w[i].ck)res++;
	}
	printf("%d\n", res);
}