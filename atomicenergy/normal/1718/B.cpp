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
		vector<long long> u(2, 1);
		while (u.back() < 10000000000) {
			u.push_back(u.back() + u[u.size() - 2]);
		}
		long long sum = 0;
		set<pair<int, int> > s;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			sum += x;
			s.insert({ x, i });
			v.push_back(x);
		}
		if (sum == 1) {
			cout << "YES" << endl;
			continue;
		}
		else if (n == 1) {
			cout << "NO" << endl;
			continue;
		}
		int cr = -1;
		for (int i = u.size() - 1; i >= 0; i--) {
			if (sum == u[i] - 1) {
				bool ok = true;
				for (int j = i - 2; j >= 0; j--) {
					pair<int, int> k = *(s.rbegin());
					if (cr == k.second) {
						auto it = s.end();
						it--;
						it--;
						k = *(it);
					}
					if (k.first < u[j]) ok = false;
					pair<int, int> kk = k;
					cr = k.second;
					kk.first -= u[j];
					s.erase(k);
					s.insert(kk);
					
				}
				if (ok) {
					cout << "YES" << endl;
				}
				else  {
					cout << "NO" << endl;
				
				}
				i = -1;
				continue;
			}
			if (i == 0) {
				cout << "NO" << endl;
				continue;
			}
		}
	}
}