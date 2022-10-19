#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 12;

int W, N, M;
int occ[MAX];
int cnt[MAX][MAX];

void load() {
	scanf("%d%d%d", &W, &N, &M);
	while (N--) {
		int x;
		scanf("%d", &x);
		occ[x]++;
	}
}

void solve() {
	for (int i = 0; i < 1 << W; i++) 
		for (int j = 0; j < 1 << W; j++)
			cnt[j][j & i] += occ[i];
		
	while (M--) {
		char gate[15];
		scanf("%s", gate);
		reverse(gate, gate + W);
		
		int mask = 0;
		for (int i = 0; i < W; i++)
			if (islower(gate[i])) {
				mask |= 1 << i;
				gate[i] = toupper(gate[i]);
			}
		
		int fixed = 0, rest = 0, diff = 0;
		int a = 0, o = 0, x = 0;
		for (int i = 0; i < W; i++)
			if (gate[i] == 'X') {
				x |= 1 << i;
				rest |= 1 << i;
				if (mask >> i & 1)
					diff |= 1 << i;
			}
			else if (gate[i] == 'A') {
				if (mask >> i & 1) {
					fixed |= 1 << i;
					rest |= 1 << i;
				}
				else 
					a |= 1 << i;
			}
			else {
				if (mask >> i & 1) 
					o |= 1 << i;
				else
					rest |= 1 << i;
			}
		
		int ans = 0;
		for (int i = a; ; i = (i - 1) & a) {
			for (int j = o; ; j = (j - 1) & o) {
				for (int k = x; ; k = (k - 1) & x) {
					if (__builtin_popcount(i) + __builtin_popcount(j) & 1)
						ans -= cnt[rest ^ i ^ j][fixed ^ i ^ k] * cnt[rest ^ i ^ j][fixed ^ i ^ k ^ diff];
					else
						ans += cnt[rest ^ i ^ j][fixed ^ i ^ k] * cnt[rest ^ i ^ j][fixed ^ i ^ k ^ diff];
					if (!k)
						break;
				}
				if (!j)
					break;
			}
			if (!i)
				break;
		}
		
		printf("%d\n", ans);
	}
}

int main() {
	load();
	solve();
	return 0;
}