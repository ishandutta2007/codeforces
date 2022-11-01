#include <bits/stdc++.h>
using namespace std;




int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cout << maxi + x << " ";
		maxi = max(maxi, maxi + x);
	}
	return 0;
}