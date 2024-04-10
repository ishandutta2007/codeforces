#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n;
int	a[M], ans = 0;

void read() {
	cin >> n;
	for (int i = 2; i < (1 << (n + 1)); ++i)
		cin >> a[i];
}

int get(int x) {
	if (2 * x >= (1 << (n + 1)))
		return a[x];
	int A = get(2 * x), b = get(2 * x + 1);
	ans += max(A, b) - min(A, b);
	return max(A, b) + a[x];
}

int main() {
	read();
	get(1);
	cout << ans << "\n";
	return 0;
}