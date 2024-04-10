#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 200 + 10;


void solve() {
	int n;
	cin >> n;
	set<int> s1, s2;
	int cnt2 = 0;
	set<int> mol;
	ll sum = 0;
	ll sums1 = 0;
	for (int i = 0; i < n; ++i) {
		int tp, d;
		cin >> tp >> d;
		if (d > 0) {
			sum += d;
			s1.insert(d);	
			sums1 += d;
		} else {
			sum -= (-d);
			if (s1.count(-d)) {
				s1.erase(-d);	
				sums1 -= (-d);
			} else {
				s2.erase(-d);
			}
		}

		if (tp != 0) {
			if (d > 0) {
				cnt2++;
				mol.insert(d);
			} else {
				cnt2--;
				mol.erase(-d);
			}
		}

		while ((int)s1.size() > cnt2) {
			int x = *(s1.begin());
			sums1 -= x;
			s1.erase(x);
			s2.insert(x);
		}

		while ((int)s1.size() < cnt2) {
			int x = *prev(s2.end());
			sums1 += x;
			s2.erase(x);
			s1.insert(x);
		}

		while (!s1.empty() && !s2.empty() && *s1.begin() < *prev(s2.end())) {
			int x = *s1.begin();
			int y = *prev(s2.end());
			sums1 += (y - x);		
			s1.erase(x);
			s2.insert(x);
			s1.insert(y);
			s2.erase(y);
		}

		int add = 0;
		if (s2.empty() && !s1.empty()) {
			add = *s1.begin();
		} else if (!s1.empty() && *mol.begin() == *s1.begin()) {
			add += *mol.begin();
			add -= *prev(s2.end());
		}

		//cout << sum + sums1 - add << "\n";
		cout << sum + sums1 - add << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}