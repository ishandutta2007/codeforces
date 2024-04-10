#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(auto &&x : v)
		cin >> x.first >> x.second;

	int k;
	cin >> k;

	int ans = 0;
	for(auto &&x : v)
		ans += x.second >= k;
	cout << ans;
	return 0;
}