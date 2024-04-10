#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	pair<int, int> ans { 1 << 30, 1 << 30 };
	for (int t = 1; t <= 100; ++t) {
		const int res = accumulate(a.begin(), a.end(), 0, [&t](const int &acc, const int &x) {
			return acc + min(abs(x-t), min(abs(x-t+1), abs(x-t-1)));
		});
		if(res < ans.second)
			ans = {t, res};
	}
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}