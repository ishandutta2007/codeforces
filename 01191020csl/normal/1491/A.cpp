#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int n, q, cnt = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt += a[i];
	for (int i = 1; i <= q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			cnt -= a[x], a[x] = 1-a[x], cnt += a[x];
		}
		else {
			int k;
			cin >> k;
			cout << (cnt>=k?1:0) << endl;
		}
	}
}