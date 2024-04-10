#include <bits/stdc++.h>
using namespace std;
#define int long long
int bou(vector<int> &a,int i) {
	int d = 0;
	int u = a.size();
	int m;
	while (u - d >= 2) {
		m = (u + d) / 2;
		if (a[m] < i) {
			d = m;
		}
		else {
			u = m;
		}
	}
	if (a[d] < i) {
		d++;
	}
	return d;
}
signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> sa(n);
	vector<int> sb(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sa = a;
	sb = b;
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	bool f = true;
	
	for (int i = 0; i < n; i++) {
		//cerr << bou(sb, a[i]) << endl;
		if (bou(sa, a[i] + 1) - bou(sb, a[i]) > 2) {
			f = false;
		}
	}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}