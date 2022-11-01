#include<bits/stdc++.h>
using namespace std;
int w[200001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long W;
		cin >> n >> W;
		for (int i = 1; i <= n; i++) cin >> w[i];
		bool flag = 0;
		for (int i = 1; i <= n; i++)
			if (w[i] <= W && w[i] >= (W+1)/2) {
				cout << 1 << endl << i << endl;
				flag = 1;
				break;
			}
		if (flag) continue;
		vector<int> ans;
		long long tot = 0;
		for (int i = 1; i <= n && tot < (W+1)/2; i++)
			if (w[i] < W) ans.push_back(i), tot += w[i];
		if (tot >= (W+1)/2) {
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
			cout << endl;
		}
		else puts("-1");
	}
}