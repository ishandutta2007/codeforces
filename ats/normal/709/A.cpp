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
	int n, b, d;
	cin >> n >> b >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int c = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= b) {
			c += a[i];
			if (c > d) {
				c = 0;
				res++;
			}
		}
	}
	cout << res << endl;
	
}