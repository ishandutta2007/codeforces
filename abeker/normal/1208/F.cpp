#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 21;

int N;
int a[MAXN];
int mx1[MAXN], mx2[MAXN];
int pos1[MAXN], pos2[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int calc(int x) {
	int res = 0, mask = 0;
	for (int i = 20; i >= 0; i--) {
		if (a[x] >> i & 1) {
			res |= 1 << i;
			continue;
		}
		if (mx2[mask | 1 << i] > x) {
			res |= 1 << i; 
			mask |= 1 << i;
		}
	}
	return res;
}

inline void upd(int &x, int y) {
	if (x < y)
		x = y;
}

void dfs(int x) {
	bio[x] = true;
	
	vector <int> ch;
	for (int i = 0; i < 21; i++)
		if (!(x >> i & 1)) {
			ch.push_back(x | 1 << i);
			if (!bio[ch.back()])
				dfs(ch.back());
		}
	
	mx1[x] = pos1[x];
	for (auto it : ch)
		upd(mx1[x], mx1[it]);
	
	if (mx1[x] != pos1[x])
		upd(mx2[x], pos1[x]);
	if (mx1[x] != pos2[x])
		upd(mx2[x], pos2[x]);
	for (auto it : ch) {
		if (mx1[x] != mx1[it])
			upd(mx2[x], mx1[it]);
		if (mx1[x] != mx2[it])
			upd(mx2[x], mx2[it]);
	}
}

int solve() {
	for (int i = 1; i <= N; i++)
		if (i >= pos1[a[i]]) {
			pos2[a[i]] = pos1[a[i]];
			pos1[a[i]] = i;
		}
		else
			upd(pos2[a[i]], i);
			
	dfs(0);
	
	int sol = 0;
	for (int i = N - 2; i; i--)
		sol = max(sol, calc(i));
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}