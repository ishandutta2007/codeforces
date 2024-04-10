#include <bits/stdc++.h>

using namespace std;

long long n, a[200005], k;

string s;

int main() {
	cin >> n >> k;
	long long cur = 0, top = 0, tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> s;
	s += '0';
	for (int i = 1; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			sort(a + cur, a + top + 1);
			for (int j = top; j >= max(top - k + 1, cur); j--) {
				tot += a[j];
			}
			cur = i;
			top = i;
		} else {
			top = i;
		}
	}
	cout << tot << endl;
	return 0;
}