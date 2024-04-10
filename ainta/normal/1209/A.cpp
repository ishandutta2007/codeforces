#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int w[110], vis[110], res;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			for (j = i; j <= n; j++) {
				if (w[j] % w[i] == 0)vis[j] = 1;
			}
			res++;
		}
	}
	printf("%d\n", res);
}