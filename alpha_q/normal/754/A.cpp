#include <bits/stdc++.h> 

using namespace std;

const int N = 105;

int n, a[N], f = 0, sum = 0;

int main (int argc, char const *argv[]) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		if (a[i] != 0) f = 1;
	}
	if (f == 0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	if (sum != 0) {
		cout << "1\n1 " << n << endl;
		return 0;
	}
	int i = 1;
	while (a[i] == 0) ++i;
	cout << "2\n1 " << i << endl;
	cout << i + 1 << " " << n << endl;
	return 0;
}