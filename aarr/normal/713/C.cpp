#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
multiset <int> s;


int main() {
	int n;
	cin >> n;
	long long ans = 0;
	int opt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
		if (a[i] >= opt) {
			s.insert(a[i]);
		}
		else {
			ans += opt - a[i];
			s.erase(s.find(opt));
			s.insert(a[i]);
			s.insert(a[i]);
		}
		opt = *s.rbegin();
	}
	cout << ans;
	
	
	return 0;
}