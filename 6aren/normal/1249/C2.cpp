#include<bits/stdc++.h>
using namespace std;

#define int long long

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> v;
		while (n != 0) {
			v.push_back(n % 3);
			n /= 3;
		}
		v.push_back(0);
		int id = -1;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] == 2) {
				id = i;
				break;
			}
		}
		if (id != -1) {
			for (int i = id; i >= 0; i--) {
				v[i] = 0;
			}
			for (int i = id + 1; i < v.size(); i++) {
				if (v[i] == 0) {
					v[i] = 1;
					break;
				} else v[i] = 0;
			}
		}
		int res = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			res = res * 3 + v[i];
		}
		cout << res << '\n';
	}
	return 0;
}