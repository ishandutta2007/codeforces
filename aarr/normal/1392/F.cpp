#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 + 5;

long long a[N];
long long b[N];

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += (a[i] - i);
	}
	for (int i = 0; i < n; i++) {
		b[i] = i + (s / n);
		if (i < s % n) {
			b[i]++;
		}
		cout << b[i] << " ";
	}
	return 0;
}