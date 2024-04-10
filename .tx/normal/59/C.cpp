#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct mcomp {
	bool operator() (const char & a, const char & b) const {
		return a > b;
	}
};


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, l, i;
	scanf("%d\n", &k);
	string s;
	cin >> s;
	set<char, mcomp> mn;
	for (i = 0; i < k; i++) {
		mn.insert('a' + i);
	}
	l = s.size();
	for (i = 0; i < l; i++) {
		if (s[i] == '?') continue;
		if (s[i] - 'a' + 1 > k) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		mn.erase(s[i]);
	}
	for (i = l >> 1; i >= 0; i--) {
		if (s[i] == '?') {
			if (s[l - 1 - i] == '?') {
				if (!mn.empty()) {
					s[i] = s[l - 1 - i] = *mn.begin();
					mn.erase(mn.begin());
				}
				else {
					s[i] = s[l - 1 - i] = 'a';
				}
			}
			else {
				s[i] = s[l - 1 - i];
			}
		}
		if (s[l - 1 - i] == '?') {
			s[l - 1 - i] = s[i];
		}
		if (s[i] != s[l - 1 - i]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	if (!mn.empty()) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << s;


	
	
	return 0;
}//sylzkg