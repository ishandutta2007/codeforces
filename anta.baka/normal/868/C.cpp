#include <bits/stdc++.h>

using namespace std;

int n, k;
int c[(1 << 4)];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int m = 0;
		for(int j = 0; j < k; j++) {
			int b;
			cin >> b;
			m = m * 2 + b;
		}
		c[m]++;
	}
	int cm = (1 << k);
	for(int i = 1; i < (1 << cm); i++) {
		vector<int> cnt(k, 0);
		int z = 0;
		for(int j = 0; j < 16; j++)
			if((i & (1 << j)) != 0 && c[j] != 0) {
				z++;
				for(int d = 0; d < 4; d++)
					if(j & (1 << d))
						cnt[d]++;
			}
		bool ok = true;
		for(int j = 0; j < k; j++)
			ok &= (cnt[j] <= z / 2);
		if(z != 0 && ok)
			return cout << "YES", 0;
	}
	cout << "NO";
}