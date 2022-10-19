#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 4e5 + 5;

int N;
int a[MAXN];
map <int, int> freq;
int cnt[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		freq[x]++;
	}
}

void solve() {
	for (auto it : freq)
		cnt[it.second]++;
	
	for (int i = N; i; i--)
		cnt[i] += cnt[i + 1];
	
	int tot = 0;
	int optA = 0, optB = 0;
	for (int a = 1; a <= N; a++) {
		tot += cnt[a];
		int b = tot / a;
		if (a <= b && a * b > optA * optB) {
			optA = a;
			optB = b;
		}
	}
	
	vector <pii> tmp;
	for (auto it : freq)
		tmp.push_back({min(it.second, optA), it.first});
	sort(tmp.begin(), tmp.end(), greater <pii> ());
	
	vector <int> all;
	for (auto it : tmp)
		while (it.first--)
			all.push_back(it.second);
			
	vector <vector <pii>> cells(optB);
	for (int j = 0; j < optB; j++)
		for (int i = 0; i < optA; i++)
			cells[(i - j + optB) % optB].push_back({i, j});
	
	int ptr = 0;
	vector <vector <int>> ans(optA);
	for (int i = 0; i < optA; i++)
		ans[i].resize(optB);
	for (int i = 0; i < optB; i++)
		for (auto it : cells[i])
			ans[it.first][it.second] = all[ptr++];
	
	printf("%d\n%d %d\n", optA * optB, optA, optB);
	for (int i = 0; i < optA; i++) {
		for (int j = 0; j < optB; j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
}

int main() {
	load();
	solve();
	return 0;
}