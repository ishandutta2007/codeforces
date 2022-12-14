#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for (int i = 1; i <= k; i++){
		int x;
		cin >> x;
		x -= n;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	if (a[0] > 0 or a.back() < 0)
		return cout << -1 << endl, 0;
	bitset<2001> bs;
	bs.reset();
	k = a.size();
	for (int i = 0; i < k; i++){
		bs[1000 + a[i]] = 1;
		if (a[i] == 0)
			return cout << 1 << endl, 0;
	}

	for (int i = 2; ; i++){
		bitset<2001> now;
		now.reset();
		for (int j = 0; j < k; j++){
			if (a[j] > 0)
				now |= (bs << a[j]);
			else
				now |= (bs >> abs(a[j]));
		}
		if (now[1000] == 1)
			return cout << i << endl, 0;
		bs = now;
	}
}