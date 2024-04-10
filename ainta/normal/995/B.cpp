#include<cstdio>
#include<algorithm>
using namespace std;
int w[220], res;
struct point {
	int b, e;
}P[110];
int n;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n+n; i++) {
		scanf("%d", &w[i]);
		if (!P[w[i]].b)P[w[i]].b = i;
		else P[w[i]].e = i;
	}
	for (i = 1; i <= n; i++) {
		for (j = i+1; j <= n; j++) {
			int x = i, y = j;
			if (P[i].b > P[j].b) swap(x, y);
			if (P[y].b < P[x].e) {
				if (P[y].e < P[x].e)res += 2;
				else res++;
			}
		}
	}
	printf("%d\n", res);
}