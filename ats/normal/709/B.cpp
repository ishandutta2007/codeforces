#include <algorithm>
#include <cstdio>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <cassert>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	vector <int> x(n);
	
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	sort(x.begin(), x.end());
	
	int res;
	int a1 = abs(a - x[0]) + x[n - 2] - x[0];
	int a2 = abs(a - x[n - 2]) + x[n - 2] - x[0];
	int a3 = abs(a - x[1]) + x[n - 1] - x[1];
	int a4 = abs(a - x[n - 1]) + x[n - 1] - x[1];
	cout << min(min(a1, a2), min(a3, a4)) << endl;

	return 0;
}