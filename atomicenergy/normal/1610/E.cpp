
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


long long mod = 1000000007;
int main()
{
	int tests;
	cin >> tests;
	while (tests-- > 0) {
		int n;
		cin >> n;
		map<int, int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s[x]++;
		}
		int mx = 1;
		for (auto p : s) {
			int curct = p.second;
			int curat = p.first;
			int curstart = p.first;
			while (true) {
				
			
				auto it = s.lower_bound({ curat * 2 - curstart + (curat == curstart?1:0) });
				if (it == s.end()) {
					mx = max(mx, curct);
					break;
				}
				else {
					curat = (*it).first;
					curct++;
				}
			}
		}
		cout << n-mx << endl;

	}
}