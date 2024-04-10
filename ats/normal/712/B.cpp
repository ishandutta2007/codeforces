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
	string s;
	cin >> s;
	int x, y;
	x = y = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			y++;
		}
		if (s[i] == 'D') {
			y--;
		}
		if (s[i] == 'R') {
			x++;
		}
		if (s[i] == 'L') {
			x--;
		}
	}

	if (s.size()%2!=0) {
		cout << -1 << endl;
	}
	else {
		cout << ((abs(x) + abs(y)) / 2) << endl;
	}

	return 0;
}