#include <bits/stdc++.h>

using namespace std;

int n, a[100];
long long k, sum[2000000], ans;
vector<int> bou;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		k += a[i];
		int x = 1;
		while(x <= a[i]) {
			int bl = x, br = a[i];
			while(bl < br) {
				int bm = (bl + br) / 2;
				if(bl == bm) bm++;
				if((a[i] + x - 1) / x == (a[i] + bm - 1) / bm) bl = bm;
				else br = bm - 1;
			}
			bou.push_back(x);
			bou.push_back(bl);
			x = bl + 1;
		}
	}
	sort(bou.begin(), bou.end());
	bou.erase(unique(bou.begin(), bou.end()), bou.end());
	int sz = bou.size();
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < n; j++) sum[i] += (a[j] + bou[i] - 1) / bou[i];
	for(int i = 0; i < sz; i++) {
		if(bou[i] * sum[i] > k) continue;
		long long bl = bou[i], br = (i != sz - 1 ? bou[i + 1] : 1000000000000LL);
		if(i != sz - 1 && sum[i] != sum[i + 1]) br--;
		while(bl < br) {
			long long bm = (bl + br) / 2;
			if(bl == bm) bm++;
			if(bm * sum[i] <= k) bl = bm;
			else br = bm - 1;
		}
		ans = bl;
	}
	cout << ans;
}