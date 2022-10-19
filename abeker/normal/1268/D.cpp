#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

int N;
bitset <MAXN> out[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char row[MAXN];
		scanf("%s", row);
		for (int j = 0; j < N; j++)
			if (row[j] == '1')
				out[i].set(j);
	}
}

bool good() {
	int node = -1, maks = 0;
	for (int i = 0; i < N; i++) {
		int tmp = out[i].count();
		if (tmp > maks) {
			maks = tmp;
			node = i;
		}
	}
	bitset <MAXN> lft, rig;
	lft.set(node);
	rig = out[node];
	while (rig.any()) {
		bitset <MAXN> all = lft | rig;
		all.flip();
		int x = all._Find_first();
		if (x >= N)
			return false;
		lft.set(x);
		rig &= out[x];
	}
	return true;
}

void flip(int x) {
	for (int i = 0; i < N; i++) 
		if (i != x) {
			out[i].flip(x);
			out[x].flip(i);
		}
}

void brute() {
	int mini = N + 1, cnt = 0;
	for (int i = 0; i < 1 << N; i++) {
		vector <int> subset;
		for (int j = 0; j < N; j++)
			if (i >> j & 1)
				subset.push_back(j);
		for (auto it : subset)
			flip(it);
		bool ok = good();
		for (auto it : subset)
			flip(it);
		if (ok && subset.size() <= mini) {
			mini = subset.size();
			if (subset.size() < mini)
				cnt = 0;
			cnt++;
		}
	}
	if (mini > N) {
		puts("-1");
		return;
	}
	for (int i = 1; i <= mini; i++)
		cnt *= i;
	printf("%d %d\n", mini, cnt);
}

bool check(int x) {
	flip(x);
	bool res = good();
	flip(x);
	return res;
}

void solve() {
	if (N <= 6) {
		brute();
		return;
	}
	if (good()) {
		puts("0 1");
		return;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		cnt += check(i);
	printf("1 %d\n", cnt);
}

int main() {
	load();
	solve();
	return 0;
}