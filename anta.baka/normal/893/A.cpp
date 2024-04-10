#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n; int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int x = 3;
	bool ok = true;
	for(int j = 0; j < n; j++)
		if(a[j] == x) { ok = false; break; }
		else {
			int y = 1;
			if(a[j] == 1 || x == 1) {
				y = 2;
				if(a[j] == 2 || x == 2) y = 3;
			}
			x = y;
		}
	cout << (ok ? "YES" : "NO");
}