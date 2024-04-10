#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, c;
vector<int> a(1000, -1);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> c;
	for(int i = 0; i < m; i++) {
		int p; cin >> p;
		if(p <= (c/2)) {
			for(int j = 0; j < n; j++)
				if(a[j] == -1 || p < a[j]) {
					a[j] = p;
					cout << j + 1 << endl;
					break;
				}
		} else {
			for(int j = n - 1; j >= 0; j--)
				if(a[j] == -1 || p > a[j]) {
					a[j] = p;
					cout << j + 1 << endl;
					break;
				}
		}
		bool ok = (a[0] != -1);
		for(int j = 1; j < n; j++)
			ok &= (a[j - 1] <= a[j]);
		if(ok) break;
	}
}