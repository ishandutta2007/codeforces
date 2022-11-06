#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<pair<char, int>> v;
	for (const char c : s)
		if (v.empty() || c != v.back().first)
			v.push_back( { c, 1 });
		else
			v.back().second++;

	int ans = 0;
	map<char, int> occ;
	for (pair<char, int> &e : v)
		ans = max(ans, occ[e.first] += e.second / k);
	cout << ans;
	return 0;
}