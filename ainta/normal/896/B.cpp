#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, c, p1, p2, w[1010];
void Print(int a) {
	printf("%d\n", a);
	fflush(stdout);
}
int main() {
	int i, a;
	scanf("%d%d%d", &n, &m, &c);
	p1 = 0, p2 = n + 1;
	while (p1 + 1 < p2) {
		scanf("%d", &a);
		if (a * 2 <= c) {
			for (i = 1; i <= p1; i++)if (w[i] > a)break;
			Print(i);
			w[i] = a;
			if (p1 < i)p1 = i;
		}
		else {
			for (i = n; i >= p2; i--)if (w[i] < a)break;
			Print(i);
			w[i] = a;
			if (p2 > i)p2 = i;
		}
	}
}