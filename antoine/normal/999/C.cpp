// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<pair<char, int>> v;
	for (int i = 0; i < n; ++i)
		v.push_back({ s[i], i});
	sort(v.begin(), v.end());

	map<int, char> mp;
	for (int i = k; i < n; ++i)
		mp[v[i].second] = v[i].first;
	for (auto &&x : mp)
		cout << x.second;
	return 0;
}