#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int n, k, a[100000], b[100000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		int l = max(0, i - k), r = min(n - 1, i + k);
		if(!a[i]) {
			b[i] = r - l + 1;
			cout << b[i] << ' ';
			continue;
		}
		a[i]--;
		l = max(l, a[i] + k + 1);
		if(l >= n) b[i] = b[a[i]];
		else b[i] = b[a[i]] + (r - l + 1);
		cout << b[i] << ' ';
	}
}