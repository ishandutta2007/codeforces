// https://codeforces.com/group/sd4r2IvEfL/contest/289090/problem/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	int diff = 0;
	for (int i = 0; (1 << i) < n; ++i) {
		vector<int> vec;
		for (int j = 0; j < n; ++j) if ((j >> i) & 1) vec.push_back(j + 1);
		if (vec.empty()) continue;
		cout << "? " << (int) vec.size();
		for (int j : vec) cout << ' ' << j;
		cout << endl;
		int xorsum;
		cin >> xorsum;
		diff ^= int(xorsum != (((int) vec.size() & 1) ? x : 0)) << i;
	}

	int k = __builtin_ctz(diff), a = 0;
	for (int i = 0; (1 << i) < n; ++i) if (i != k) {
		vector<int> vec;
		for (int j = 0; j < n; ++j) if (((j >> i) & 1) && !((j >> k) & 1)) vec.push_back(j + 1);
		if (vec.empty()) continue;
		cout << "? " << (int) vec.size();
		for (int j : vec) cout << ' ' << j;
		cout << endl;
		int xorsum;
		cin >> xorsum;
		a ^= int(xorsum != (((int) vec.size() & 1) ? x : 0)) << i;
	}
	
	int b = a ^ diff;
	if (a > b) swap(a, b);
	cout << "! " << a + 1 << ' ' << b + 1 << endl;
}