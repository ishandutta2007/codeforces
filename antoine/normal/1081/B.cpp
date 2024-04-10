#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	map<int, vector<int>> mp;

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		mp[n-x].push_back(i);
	}

	for(auto &&x : mp)
		if(x.second.size() % x.first) {
			cout << "Impossible\n";
			return 0;
		}


	vector<int> ans(n);
	int curr = 0;

	for(auto &&x : mp) {
		for(int i = 0; i < (int)x.second.size(); ++i) {
			curr += i % x.first == 0;
			ans[x.second[i]] = curr;
		}
	}
	cout << "Possible\n";
	for(int x : ans)
		cout << x << ' ';
	return 0;
}