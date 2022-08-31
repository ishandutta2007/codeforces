#include<cstdio>
#include<algorithm>
using namespace std;
int L[1010], R[1010], n, P[1010];
struct point {
	int x, num;
	bool operator <(const point &p)const {
		return x < p.x;
	}
}w[1010];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &L[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &R[i]);
		w[i] = { L[i] + R[i],i };
	}
	sort(w + 1, w + n + 1);
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		cnt++;
		for (j = i; j <= n&&w[j].x == w[i].x; j++) {
			P[w[j].num] = n + 1 - cnt;
		}
		i = j - 1;
	}
	for (i = 1; i <= n; i++) {
		int c1 = 0, c2 = 0;
		for (j = 1; j <= n; j++) {
			if (P[j] > P[i] && j < i)c1++;
			if (P[j] > P[i] && j > i)c2++;
		}
		if (L[i] != c1 || R[i] != c2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (i = 1; i <= n; i++)printf("%d ", P[i]);
}