#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	map<int, int> mp;
	int a;
	int mx = 0;
	vector<pair<int, int> > vp;
	for (int i = 0; i < N; i++) {
		cin >> a;
		mp[a]++;
		mx = max(mx, mp[a]);
	}
	for (auto m : mp) {
		vp.emplace_back(m.second, m.first);
	}
	sort(vp.rbegin(), vp.rend());
	int H;
	int t = 0;
	int tot = N;
	for (int i = N; i >= 1; i--) {
		int w = min((int)vp.size(), (tot / i));
		if (i <= vp.size() && w >= i) {
			//int w = tot / i;
			//if(w >= i){
			int area = i * w;
			if (t < area) {
				t = area;
				H = i;
			}
		}
		for (int j = 0; j < vp.size(); j++) {
			if (vp[j].first == i) {
				vp[j].first--;
				tot--;
			} else {
				break;
			}
		}
	}
	vp.clear();
	for (auto m : mp) {
		vp.emplace_back(m.second, m.first);
	}
	sort(vp.rbegin(), vp.rend());

	tot = N;
	for (int i = N; i > H; i--) {
		for (int j = 0; j < vp.size(); j++) {
			if (vp[j].first == i) {
				vp[j].first--;
				tot--;
			} else {
				break;
			}
		}
	}
	vector<int> A;
	for (int i = 0; i < vp.size(); i++) {
		for (int j = 0; j < vp[i].first; j++) {
			A.push_back(vp[i].second);
		}
	}
	int W = min((int)vp.size(), (tot / H));
	//int W = tot / H;
	vector<vector<int> > res(H, vector<int>(W));
	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			res[i][(i + j) % W] = A[j * H + i];
		}
	}
	cout << H * W << endl;
	cout << H << " " << W << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (j > 0) cout << " ";
			cout << res[i][j];
		}
		cout << endl;
	}
}