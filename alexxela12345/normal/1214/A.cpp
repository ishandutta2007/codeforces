#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	int min_lst = n;
	for (int dd = 0; dd * d <= n; dd++) {
		int lst = n - (n - dd * d) / e * e - dd * d;
		min_lst = min(min_lst, lst);
	}
	cout << min_lst << endl;
}