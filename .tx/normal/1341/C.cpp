#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
			b[a[i]] = i;
		}
		vector<int> used(n), bused(n);
		int z = 0;
		bool ok = true;
		while (z < n) {
			if (bused[z]) {
				z++;
				continue;
			}
			int p = b[z];
			used[p] = 1;
			bused[z] = 1;
			while (p + 1 < n && !used[p + 1]) {
				if (a[p] + 1 != a[p + 1]) {
					ok = false;
					break;
				}
				bused[a[p + 1]] = 1;
				used[p + 1] = 1;
			}
		}
		if (ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}

	return 0;
}