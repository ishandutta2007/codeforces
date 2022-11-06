#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	n = (int) v.size();

	if (n == 1)
		cout << 0;
	else if (n == 2) {
		const int diff = v[1] - v[0];
		cout << (diff & 1 ? diff : diff >> 1);
	} else if (n == 3 && v[2] - v[1] == v[1] - v[0]) {
		cout << v[1] - v[0];
	} else
		cout << -1;
	return 0;
}