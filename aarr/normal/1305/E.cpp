#include <bits/stdc++.h>
using namespace std;


const int N = 5005, M = 100 * 1000 * 1000 + 5;

int a[N];
int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m == 0) {
		for (int i = 1; i <= n; i++) {
			cout << M + i << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (m > (i - 1) / 2) {
		//	cout << m << " " << (i - 1) / 2 << endl;
			a[i] = i;
			m -= (i - 1) / 2;
		}
		else {
	//		cout << i << " " << m << endl;
			a[i] = a[i - 1] + a[i - 2 * m];
			for (int j = i + 1; j <= n; j++) {
				a[j] = M + j * (n * 2 + 1);
			}
			m = 0;
			break;
		} 
	}
//	cout << m << endl;
	if (m > 0) {
		cout << -1;
	}
	else {
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}