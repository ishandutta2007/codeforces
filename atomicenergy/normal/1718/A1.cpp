#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;



int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		vector<long long> v;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			v.push_back(x);
		}
		v.push_back(0);
		long long ans = 0;
		set<long long> s;
		long long cr = 0;
		s.insert(0);
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) {
				s.clear();
				cr = 0;
				s.insert(0);

				continue;
			}
			ans++;
			cr ^= v[i];
			if (s.count(cr)) {
				ans--;
				s.clear();
				cr = 0;
				s.insert(0);

			}
			else {
				s.insert(cr);
			}
		}
		cout << ans << endl;

	}
}