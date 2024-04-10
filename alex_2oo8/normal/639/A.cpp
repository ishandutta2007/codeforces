#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

int t[MX], ok[MX], f[7];

int main() {
	int n, k, q;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 0; i < n; i++) scanf("%d", t + i);
	for (int i = 0; i < q; i++) {
		int g, id;
		scanf("%d %d", &g, &id);
		id--;
		
		if (g == 1) {
			ok[id] = 1;
			f[0] = t[id];
			sort(f, f + k + 1);
		}
		else if (ok[id] == 1 && t[id] >= f[1]) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}