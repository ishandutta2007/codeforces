#include <bits/stdc++.h>
using namespace std;

const int LOG = 11;

int N, K;
vector <vector <int>> paths[LOG];
bool useless[1 << LOG];

void load() {
	scanf("%d%d", &N, &K);
}

vector <int> shift(vector <int> v, int lim, int val) {
	for (auto &it : v)
		if (it >= lim)
			it += val;
	return v;
}

void init() {
	paths[1].push_back({0, 1});
	for (int i = 2; i < LOG; i++) {
		for (auto it : paths[i - 1]) {
			paths[i].push_back(shift(it, 0, 1 << i - 2));
			paths[i].push_back(shift(it, 1 << i - 2, 1 << i - 1));
		}
		for (int j = 0; j < 1 << i - 2; j++)
			for (int k = 0; k < 1 << i - 1; k++)
				paths[i].push_back({j, k + (1 << i - 2), j + 3 * (1 << i - 2)});
	}
}

void answer(int ans) {
	printf("! %d\n", ans);
	fflush(stdout);
	exit(0);
}

void ask(vector <int> v) {
	for (auto it : v) 
		for (int i = 0; i < K / 2; i++) {
			int cafe = it * K / 2 + i;
			printf("? %d\n", cafe + 1);
			fflush(stdout);
			char ans;
			scanf(" %c", &ans);
			useless[cafe] |= ans == 'Y';
		}
	puts("R");
	fflush(stdout);
}

void solve() {
	if (N == 1)
		answer(1);
	K = max(K, 2);
	
	int lg = 1;
	for (int i = K; i < N; i *= 2)
		lg++;
	
	for (auto it : paths[lg]) 
		ask(it);
	
	int distinct = 0;
	for (int i = 0; i < N; i++) 
		distinct += !useless[i];
	
	answer(distinct);
}

int main() {
	init();
	load();
	solve();
	return 0;
}