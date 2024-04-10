#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(k, 0);
		for(int i = 0; i < n; ++i)
			++v[i%k];
		for(int i = 0; i < k; ++i)
			cout << string(v[i], 'a' + i);
		cout << '\n';
	}
	return 0;
}