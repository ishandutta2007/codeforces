#include <bits/stdc++.h>
using namespace std;


const int N = 105;

int a[N], b[N];
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		sort(a, a + n);
		sort(b, b + n);
		for (int j = 0; j < n; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << b[j] << " ";
		}		
		cout << endl;
	}
	return 0;
}