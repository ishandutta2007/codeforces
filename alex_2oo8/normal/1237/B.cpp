#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

int a[MX], b[MX];
bool dead[MX + 1];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	for (int i = 0; i < n; i++) ignore = scanf("%d", b + i);
	
	int ans = 0;
	for (int i = n - 1, j = n - 1; i >= 0; i--) {
		while (dead[b[j]]) j--;
		if (b[j] != a[i]) ans++;
		dead[a[i]] = true;
	}
	
	printf("%d\n", ans);
	
	return 0;
}