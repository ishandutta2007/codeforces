#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int a[10000];

int main() {
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if ((int)s.size() > 5)
			a[i] = 1;
		else
			a[i] = 0;
	}
	ll now = 0;
	ll nn = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 1) {
			nn += now * p;
			nn += p / 2;
			now = now * 2 + 1;
		}
		else {
			nn += now * p;
			now *= 2;
		}
	}
	cout << nn << "\n";
	return 0;
}