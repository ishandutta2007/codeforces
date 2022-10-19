#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> which[4];
	for(int i = 0; i < 4; ++i) which[i].push_back(0);
	int sz[4];
	
	for(int i = 0; i < n; ++i) {
		int type, val;
		cin >> type >> val;
		if(type == 00) which[0].push_back(val);
		if(type == 01) which[1].push_back(val);
		if(type == 10) which[2].push_back(val);
		if(type == 11) which[3].push_back(val);
	}
	
	// 01 is always more
	if(which[1].size() > which[2].size())
		swap(which[1], which[2]);
	
	for(int i = 0; i < 4; ++i) {
		sz[i] = -1+(int)which[i].size();
		sort(which[i].begin(), which[i].end());
		reverse(which[i].begin()+1, which[i].end());
		for(int j = 1; j < which[i].size(); ++j)
			which[i][j] += which[i][j-1];
	}
		
	
	ll best = 0;
	for(int diff = -sz[1]; diff <= sz[2]; ++diff) {
		ll score = which[3].back();
		score += which[2][min(sz[2], sz[1]+diff)];
		score += which[1][min(sz[1], sz[2]-diff)];
		if(sz[3]-abs(diff) < 0) continue;
		score += which[0][max(0, min(sz[0] , sz[3]-abs(diff)))];
		best = max(best, score);
	}
	cout << best << "\n";
}