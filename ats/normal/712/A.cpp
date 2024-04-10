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
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			cout << a[i] + a[i - 1] << " ";
		}
	}
	cout << a[n - 1] << endl;
	return 0;
	
}