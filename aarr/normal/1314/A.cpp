#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

pair <int, int> a[N];
multiset <int> s;
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	} 
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	sort(a, a + n);
	int t = a[0].first, x = 0;
	long long ans = 0;
	long long sm  =0;
	while (x < n || s.size()) {
	//	cout << t << " " << x << " " << sm << endl;
		while (a[x].first == t && x < n) {
			s.insert(-a[x].second);
			sm += a[x].second;
			x++;
		}
		if (s.size()) {
			sm += *s.begin();
		//	cout << sm << endl;
			ans += sm;
			s.erase(s.begin());
		}
		if (s.size()) {
			t++;
		}
		else {
			t = a[x].first;
		}
	}
	cout << ans;
	return 0;
}