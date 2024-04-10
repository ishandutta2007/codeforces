#include <bits/stdc++.h>
using namespace std;

int n, s1, s2, a[100000];

bool ok(int d) {
	set<int> x;
	x.insert(s1);
	x.insert(s2);
	for(int i = 0; i < n; i++) {
		while(!x.empty() && *x.begin() + d < a[i]) x.erase(x.begin());
		while(!x.empty() && *x.rbegin() - d > a[i]) x.erase(--x.end());
		if(x.empty()) return false;
		x.insert(a[i]);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s1 >> s2;
	for(int i = 0; i < n; i++) cin >> a[i];
	int bl = abs(s1 - s2), br = 1e9;
	while(bl < br) {
		int bm = (bl + br) / 2;
		if(ok(bm)) br = bm;
		else bl = bm + 1;
	}
	cout << bl;
}