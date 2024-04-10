#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(200005, 0);
	int l,r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		l--;
		a[l]++;
		a[r]--;
	}
	for (int i = 0; i < 200003; i++) {
		a[i + 1] += a[i];
	}
	
	for (int i = 200001; i >= 1; i--) {
		if (a[i - 1] >= k) {
			a[i] = 1;
		}
		else {
			a[i] = 0;
		}
	}
	a[0] = 0;
	//cerr << "A" << endl;
	for (int i = 0; i < 200003; i++) {
		a[i + 1] += a[i];
	}
	//cerr << "A" << endl;
	vector<int> res;
	for (int i = 0; i <	q; i++) {
		cin >> l >> r;
		l--;
		res.push_back(a[r] - a[l]);
	}
	for (int i = 0; i < q; i++) {
		cout << res[i] << endl;
	}
	return 0;

}