#include <bits/stdc++.h>
using namespace std;
int deg[100010];
int bin[100010];
const int mod = 1e9 + 7;

int main() {
	bin[0] = 1;
	for(int i = 1; i <= 100000; i++) {
		bin[i] = bin[i - 1] << 1;
		bin[i] %= mod;
	}
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		++deg[p];
		++deg[q];
	}	
	int leaf = 0;
	for(int i = 1; i <= n; i++) {
		leaf += (deg[i] == 1); 
	}	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int tot = leaf;
		if(deg[i] == 1) --tot;
		ans += bin[n - tot];
		ans %= mod;
	}
	printf("%d\n", ans);
}