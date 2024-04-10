#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		if(x <= 5 || x >= n - 4 || y <= 5 || y >= m - 4) return cout << "YES", 0;
	}
	cout << "NO";
}