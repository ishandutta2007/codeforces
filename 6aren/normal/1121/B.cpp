#include <bits/stdc++.h>

using namespace std;

int n, a[1005], check[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			check[a[i] + a[j]] ++;
		}
	} 
	sort(check, check + 200005);
	cout << check[200004];
	return 0;
}