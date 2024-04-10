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

signed main() {
	
	int x, y;
	cin >> x >> y;
	int a[3];
	a[0] = a[1] = a[2] = y;
	int res = 0;
	while (true) {
		a[res % 3] = min(x, a[(res+1) % 3] + a[(res+2) % 3] - 1);
		res++;
		if (a[0] == x && a[1] == x && a[2] == x) {
			break;
		}
	}
	cout << res << endl;
	
	return 0;
}