#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		cout << min(r - l, (r - 1) / 2) << '\n';
	}
}