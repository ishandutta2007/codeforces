#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int> a = {x};
	for(int i = 1; i < n; i++) {
		int y; cin >> y;
		if(y % x) return cout << -1, 0;
		a.push_back(y);
		a.push_back(x);
	}
	cout << a.size() << endl;
	for(int z : a) cout << z << ' ';
}