#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	deque <pii> d;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			d.push_back({i, j});
	
	vector <pii> ans;
	for (int i = 0; i < N * M; i++)
		if (i % 2) {
			ans.push_back(d.back());
			d.pop_back();
		}
		else {
			ans.push_back(d.front());
			d.pop_front();
		}
	
	set <pii> diffs;
	for (int i = 1; i < ans.size(); i++)
		diffs.insert({ans[i].first - ans[i - 1].first, ans[i].second - ans[i - 1].second});
	
	assert(diffs.size() == N * M - 1);
	
	for (auto it : ans)
		printf("%d %d\n", it.first, it.second);
		
	return 0;
}