#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int pos = 0, neg = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pos += x > 0;
		neg += x < 0;
	}
	if (pos >= n / 2.0)
		cout << 1;
	else if (neg >= n / 2.0)
		cout << -1;
	else
		cout << 0;
	return 0;
}