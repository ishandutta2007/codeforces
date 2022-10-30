#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int pos[2];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	string all0;
	s.clear();
	int base;
	for (int i = 0; i < N; i++) {
		s.push_back('0');
	}
	all0 = s;

	cout << "? " << s << endl;
	cout.flush();
	cin >> base;
	
	int a;
	int b;
	s[0] = '1';
	cout << "? " << s << endl;
	cout.flush();
	cin >> a;
	if (a > base) {
		pos[0] = 1;
		b = 1;
	}
	else {
		pos[1] = 1;
		b = 0;
	}
	int l = 0;
	int r = N;
	int m;
	s = all0;
	while (r - l > 1) {
		m = (r + l) / 2;
		
		for (int i = m; i < r; i++) {
			s[i] = '1';
		}
		cout << "? " << s << endl;
		cout.flush();
		cin >> a;

		for (int i = m; i < r; i++) {
			s[i] = '0';
		}
		if (b == 0) {
			if (base - a == r - m) {
				r = m;
			}
			else {
				l = m;
			}
		}
		if (b == 1) {
			if (a - base == r - m) {
				r = m;
			}
			else {
				l = m;
			}
		}

	}
	pos[b] = l + 1;
	cout << "! "<<pos[0]<<" "<<pos[1] << endl;
	cout.flush();
}