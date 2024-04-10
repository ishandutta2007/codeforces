#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	vector<pair<char, int>> v;
	for(char ch : s)
		if(v.empty() || v.back().first != ch)
			v.push_back({ch, 1});
		else v.back().second++;
	int ans = 0;
	while(v.size() > 1) {
		int sz = v.size();
		v[0].second--;
		v.back().second--;
		for(int i = 1; i < sz - 1; i++) v[i].second -= 2;
		vector<pair<char, int>> v1;
		for(pair<char, int> x : v)
			if(x.second > 0)
				if(v1.empty() || v1.back().first != x.first)
					v1.push_back(x);
				else v1.back().second += x.second;
		v = v1;
		ans++;
	}
	cout << ans;
}