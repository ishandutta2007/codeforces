#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string pa = "tokitsukaze";
	string pb = "quailty";
	string pd = "once again";
	vector<int> pos[2];
	for(int i = 0; i < n; i++) {
		pos[s[i] - '0'].push_back(i);
	}
	if(pos[0].empty() 
	|| pos[1].empty() 
	|| pos[0].back() - pos[0][0] + 1 <= k 
	|| pos[1].back() - pos[1][0] + 1 <= k) {
		cout << pa << endl;
	} else {
		bool draw = false;
		for(int i = 0; i + k - 1 < n; i++) {
			int j = i + k - 1;
			for(int z = 0; z <= 1; z++) {
				int lz = min(pos[z][0], i);
				int rz = max(pos[z].back(), j);
				int lnz, rnz;
				if(pos[1][0] < i) {
					lnz = pos[1][0];
				} else {
					auto it = upper_bound(all(pos[!z]), j);
					if(it != end(pos[!z])) {
						lnz = *it;
					} else {
						continue;
					}
				}
				if(pos[1].back() > j) {
					rnz = pos[1].back();
				} else {
					auto it = lower_bound(all(pos[!z]), i);
					if(it != begin(pos[!z])) {
						rnz = *prev(it);
					} else {
						continue;
					}
				}
				int t = min(rz - lz + 1, rnz - lnz + 1);
				draw |= t > k;
			}
		}
		if(draw) {
			cout << pd << endl;
		} else {
			cout << pb << endl;
		}
	}
	return 0;
}