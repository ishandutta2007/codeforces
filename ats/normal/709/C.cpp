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
	
	string s;
	cin >> s;
	bool f = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a') {
			f = true;
			s[i] = (char)((int)s[i] - 1);
		}
		else if (f) {
			break;
		}
	}
	if (!f) {
		s[s.size() - 1] = 'z';
	}
	cout << s << endl;
	
	return 0;
}