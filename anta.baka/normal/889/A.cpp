#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<bool> z(n, false);
	int ret = 0;
	for(int i = n - 1; i >= 0; i--)
		if(!z[i]) {
			int v = i;
			while(v != -1 && !z[v]) {
				z[v] = true;
				v = a[v] - 1;
			}
			ret++;
		}
	cout << ret;
}