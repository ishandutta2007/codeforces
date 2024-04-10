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
int ask(int a) {
	cout << "? " << a << endl;
	cout << flush;
	int res;
	cin >> res;
	return res;
}
bool check(pair<int, int> p1, pair<int, int> p2) {
		//cerr << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
	bool res = true;
	if ((p1.first < p1.second && p2.first > p2.second) ||
		(p1.first > p1.second && p2.first < p2.second)) {
		res = true;
	}
	else {
		res = false;
	}
	
	return res;
}
signed main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int res;
	if (N % 4 == 0) {
		int u = (N / 2) + 1;
		int d = 1;
		int m;
		pair<int, int> uu;
		pair<int, int> dd;
		pair<int, int> mm;
		dd.first = ask(d);
		dd.second = ask(d + (N / 2));
		uu.first = dd.second;
		uu.second = dd.first;
		if (dd.first == dd.second) {
			res = d;
			cout << "! " << d << endl << flush;
			return 0;
		}
		while (true) {
			if (u - d == 1) {
				cout << "! -1" << endl;
				cout << flush;
				return 0;
			}
			m = (u + d) / 2;
			mm.first = ask(m);
			mm.second = ask(m + (N / 2));
			if (mm.first == mm.second) {
				res = m;
				cout << "! " << m << endl << flush;
				return 0;
			}

			if (check(dd, mm)) {
				u = m;
				uu = mm;
			}
			else {
				d = m;
				dd = mm;
			}
		}
	}
	else {
		cout << "! -1" << endl;
		cout << flush;
	}
	return 0;
}