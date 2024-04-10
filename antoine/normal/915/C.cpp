#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

string a, b;

string res = "";

void f(int i, bool eq) {
	if (i == a.size()) {
		if (res.size() == 0)
			res = a;
		else
			res = max(res, a);
		return;
	}
	// leading 0
	if (eq) {
		for (int j = i; j < a.size(); ++j)
			if (a[j] == b[i]) {
				swap(a[j], a[i]);
				f(i + 1, true);
				swap(a[j], a[i]);
				break;
			}
		int bestIdx = -1;
		for (int j = i; j < a.size(); ++j)
			if (a[j] < b[i]) {
				if (bestIdx == -1)
					bestIdx = j;
				else
					if (a[j] > a[bestIdx])
						bestIdx = j;
			}
		if (bestIdx != -1) {
			swap(a[i], a[bestIdx]);
			f(i + 1, false);
			swap(a[i], a[bestIdx]);
		}
	}
	else {
		string tmp(a.begin() + i, a.end());
		sort(a.begin() + i, a.end());
		reverse(a.begin() + i, a.end());
		f(a.size(), 0);
		a = a.substr(0, i) + tmp;
	}
}

string f() {
	cin >> a >> b;
	f(0, a.size() == b.size());
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << f();
	return 0;
}