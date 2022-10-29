#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

pii operator - (pii a, pii b) {
	return pii(a.first - b.first, a.second - b.second);
}

int n;
pii cur;
vector<pii> a;
//vector<int> p;

pii readpii() {
	int x, y;
	cin >> x >> y;
	return pii(x, y);
}
pii query(int x) {
	cout << "+ " << x << endl;
//	p[--x]++;
	return readpii();
}

int main() {
	cin >> n;
//	p.resize(n);
//	for (auto& x : p) {
//		cin >> x;	
//	}
	cur = readpii();
	for (int i = n - 1; ~i; i--) {
		int p = (i > 2) ? i : ((i & 1) + 1);
		auto x = query(p);
		a.push_back(x - cur);
//		cerr << x.first << " " << x.second << endl;
		cur = x;
	}
	reverse(a.begin(), a.end());
	vector<int> b (n);
	b[0] = (-1 + sqrt(1 + 8 * a[0].first + 0.1)) / 2;
	b[2] = a[0].second - a[2].second - 1;
	b[1] = a[0].second / (b[2] + 1) - 1;
	b[3] = (a[1].second - (b[0] + 1) * (b[2] + 1)) / (b[2] + 1) - (n > 4);
	for (int i = 4; i < n; i++) {
		b[i] = (a[i - 1].second - b[i - 4] * b[i - 3] - b[i - 3] * (b[i - 1] + 1)) / (b[i - 1] + 1) - (i !=  n - 1);
	}
	cout << "!";
	for (auto x : b) {
		cout << " " << x;
	}
	cout << endl;
	return 0;
}