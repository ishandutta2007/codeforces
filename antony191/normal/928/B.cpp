#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> s(n);
	s[0] = min(k + 1, n);
	for (int i = 1; i < n; ++i) {
		s[i] = min(i, k) + min(k + 1, n - i);
		if (a[i] >= 0) {
			s[i] += s[a[i]];
			int l = max(i - k, 0);
			int r = min(a[i] + k, n - 1);
			s[i] -= max(0, r - l + 1);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", s[i]);
	return 0;
}