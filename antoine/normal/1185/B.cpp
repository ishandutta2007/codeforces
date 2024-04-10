#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<pair<char, int>> f(const string s) {
	vector<pair<char, int>> res;
	for (char c : s)
		if (res.empty() || res.back().first != c)
			res.push_back( { c, 1 });
		else
			res.back().second++;
	return res;
}

bool f(vector<pair<char, int>> v1, vector<pair<char, int>> v2) {
	if(v1.size() != v2.size()) return false;
	for(int i = 0; i < (int)v1.size(); ++i) {
		if(v1[i].first != v2[i].first)
			return false;
		if(v1[i].second > v2[i].second)
			return false;
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;

		vector<pair<char, int>> v1 = f(s), v2 = f(t);
		cout << (f(v1, v2) ? "YES" :
			"NO") << '\n';
	}
	return 0;
}