#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> dad, rnk, clr;

void init(int x) {
	if (dad.find(x) == dad.end())
		dad[x] = x;
}

int find(int x) {
	if (dad[x] == x)
		return x;
	int res = find(dad[x]);
	clr[x] ^= clr[dad[x]];
	return dad[x] = res;	
}

void join(int x, int y, int c) {
	int dx = find(x);
	int dy = find(y);
	if (dx == dy)
		return;
	if (rnk[dx] > rnk[dy])
		swap(dx, dy);
	dad[dx] = dy;
	clr[dx] ^= clr[x] ^ clr[y] ^ c;
	rnk[dy] += rnk[dx] == rnk[dy];
}

int get(int x, int y) {
	return find(x) == find(y) ? clr[x] ^ clr[y] : -1;
}

int main() {
	int Q;
	scanf("%d", &Q);
	
	int last = 0;	
	while (Q--) {
		int t, l, r, x;
		scanf("%d%d%d", &t, &l, &r);
		l ^= last;
		r ^= last;
		if (l > r)
			swap(l, r);
		r++;
		init(l);
		init(r);
		if (t == 1) {
			scanf("%d", &x);
			x ^= last;
			join(l, r, x);
		}
		else {
			last = get(l, r);
			printf("%d\n", last);
			if (last == -1)
				last = 1;
		}
	}
	
	return 0;
}