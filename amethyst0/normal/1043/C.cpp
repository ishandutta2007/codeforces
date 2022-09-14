#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = 1010;

int cnt[maxn];
int ans[maxn];

void go(string s, int it) {
	if (s.empty()) {
		return;
	}
	
	bool fl = true;
	
	int c = s.back() - 'a';
	s.pop_back();
	
	for (int i = 0; i < c; i++) {
		if (cnt[i] != 0) {
			fl = false;
		}
	}
	
	cnt[c]--;
	
	int ps = (int)s.size();
	
	if (it == 0) {
		if (!fl) {
			ans[ps] = 0;
			go(s, 0);
		} else {
			ans[ps] = 1;
			go(s, 1);
		}
	} else {
		if (fl) {
			ans[ps] = 0;
			go(s, 1);
		} else {
			ans[ps] = 1;
			go(s, 0);
		}
	}
}

int main() {
	string s;
	
	cin >> s;
	
	for (int i = 0; i < (int)s.size(); i++) {
		cnt[s[i] - 'a']++;
	}
	
	go(s, 0);
	
	for (int i = 0; i < (int)s.size(); i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}