#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[60], n, Mn = 1e9;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Mn = min(Mn, w[i]);
	}
	int c = 0;
	for (i = 1; i <= n; i++) {
		if (Mn != w[i])c++;
	}
	if (c * 2 >= n)puts("Alice");
	else puts("Bob");
}