#include <iostream>
#include <map>
#include <set>
using namespace std;

set <int> s;
int a[105];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	while (s.size()) {
		ans++;
		int x = *s.begin();
		for (int i = 0; i < n; i++) {
			if (a[i] % x == 0) {
				s.erase(a[i]);
			}
		}
	}
	cout << ans;
	return 0;
}