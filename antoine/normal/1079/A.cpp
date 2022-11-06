#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	map<int, int> occ;

	int m = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		m = max(m, ++occ[x]);
	}


	while (m % k)
		++m;

	cout << m*(int) occ.size()-n;
	return 0;
}