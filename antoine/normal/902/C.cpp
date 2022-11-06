#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h;
	cin >> h;
	vector<int> a(h + 1);
	for (int i = 0; i <= h; ++i)
		cin >> a[i];
	
	int ambig = -1;
	for(int i = 0; i < h; ++i)
		if (a[i] > 1 && a[i + 1] > 1) {
			ambig = i;
			break;
		}
	
	if (ambig == -1) {
		cout << "perfect";
		return 0;
	}
	vector<int> cs = a;
	for (int i = 1; i <= h; ++i)
		cs[i] += cs[i - 1];

	cout << "ambiguous\n0";
	for (int i = 1; i <= h; ++i)
		for (int j = 0; j < a[i]; ++j)
			cout << ' ' << cs[i - 1];

	cout << "\n0";
	for (int i = 1; i <= h; ++i)
		for (int j = 0; j < a[i]; ++j) {
			if (i == ambig + 1 && !j)
				cout << ' ' << cs[i - 1] - 1;
			else
				cout << ' ' << cs[i - 1];
		}
	
	return 0;
}