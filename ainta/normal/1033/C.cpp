#include<cstdio>
#include<algorithm>
using namespace std;
int n, D[101000], vis[101000];
struct point {
	int x, num;
	bool operator<(const point &p)const {
		return x < p.x;
	}
}w[101000];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i].x);
		w[i].num = i;
	}
	sort(w + 1, w + n + 1);
	for (i = n; i >= 1; i--) {
		int x = w[i].x;
		int t = w[i].num;
		for (j = t; j >= 1; j -= x) {
			if (vis[j] && !D[j])D[t] = 1;
		}
		for (j = t; j <= n; j += x) {
			if (vis[j] && !D[j])D[t] = 1;
		}
		vis[t] = 1;
	}
	for (i = 1; i <= n; i++) {
		printf("%c", 'A' + 1 - D[i]);
	}
}