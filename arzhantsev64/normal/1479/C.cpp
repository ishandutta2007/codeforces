#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int main() {
	int L, R;
	cin >> L >> R;
	// 1 + 19 + 1

	// 0 | 1 .. 20 | 21	
	vector<int> a;
	vector<int> b;
	vector<int> c;
	for (int i = 0; i < 22; ++i) {
		a.push_back(1);
		b.push_back(i + 2);
		c.push_back(L);
	}
	for (int i = 2; i < 23; ++i)
		for (int j = i + 1; j < 23; ++j) {
			a.push_back(i);
			b.push_back(j);
			c.push_back((1 << (i - 2)));
		}

	int T = R - L;
	int mx = L;
	while (T > 0) {
		int p = 1;
		int k = 1;
		while ((p << 1) <= T) {
			p <<= 1;
			k++;
		}
		a.push_back(k + 1);
		b.push_back(23);
		c.push_back(mx + 1 - L);
		mx += p;
		T = R - mx;
	}
	cout << "YES" << endl;
	cout << 23 << ' ' << a.size() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
	}
	return 0;
}