#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXV = 7e3 + 5;

int N, Q;
bitset <MAXV> mult[MAXN];
bitset <MAXV> divs[MAXV], inv[MAXV];

void init() {
	for (int i = MAXV - 1; i; i--) {
		inv[i].set(i);
		divs[i].set(i);
		for (int j = 2 * i; j < MAXV; j += i) {
			inv[i] ^= inv[j];
			divs[j].set(i);
		}
	}
}

int main() {
	init();
	
	scanf("%d%d", &N, &Q);
	while (Q--) {
		int t, x, y, z;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1)
			mult[x] = divs[y];
		else if (t == 4)
			printf("%d", (mult[x] & inv[y]).count() & 1);
		else {
			scanf("%d", &z);
			mult[x] = t == 2 ? mult[y] ^ mult[z] : mult[y] & mult[z];		
		}
	}
	puts("");
	
	return 0;
}