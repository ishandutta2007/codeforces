#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];
vector <int> pos[10];

void load() {
	scanf("%d%s", &N, s);
}

void solve() {
	for (int i = 0; i < 10; i++)
		pos[i].clear();
	
	for (int i = 0; i < N; i++)
		pos[s[i] - '0'].push_back(i);
	
	int last = -1;
	vector <int> one, two;
	for (int i = 0; i < 10; i++) {
		if (pos[i].empty())
			continue;
		
		vector <int> small, large;
		for (auto it : pos[i])
			if (it > last)
				large.push_back(it);
			else
				small.push_back(it);
		
		for (auto it : large)
			one.push_back(it);
		
		if (small.empty()) {
			last = large.back();
			continue;
		}
		
		for (auto it : small)
			two.push_back(it);
		for (int j = i + 1; j < 10; j++)
			for (auto it : pos[j])
				two.push_back(it);
		
		for (int j = 1; j < two.size(); j++)
			if (two[j - 1] > two[j]) {
				puts("-");
				return;
			}
		
		break;
	}
	
	string ans;
	ans.resize(N);
	for (auto it : one)
		ans[it] = '1';
	for (auto it : two)
		ans[it] = '2';
	puts(ans.c_str());
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}