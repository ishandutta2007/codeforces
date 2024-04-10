#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << a[0];
		return 0;
	}
	vector<int> p(n), s(n);
	p[0] = ~a[0];
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] & (~a[i]);
	s[n - 1] = ~a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		s[i] = s[i + 1] & (~a[i]);
	int ans, m;
	for (int i = 0; i < n; i++) {
		if (i != 0 && i != n - 1) {
			if ((p[i - 1] & s[i + 1]) >= m) {
				m = p[i - 1] & s[i + 1];
				ans = i;
			}
		}
		if (i == 0) {
			m = s[i + 1];
			ans = i;
		}
		if (i == n - 1) {
			if (p[i - 1] >= m) {
				m = p[i - 1];
				ans = i;
			}
		}
	}
	cout << a[ans] << " ";
	for (int i = 0; i < n; i++)
		if (i != ans)
			cout << a[i] << " ";
	return 0;
}