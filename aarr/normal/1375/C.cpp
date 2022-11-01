#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1000 * 1000 + 5;

int a[N];


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (a[1] < a[n]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}