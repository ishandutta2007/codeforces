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
	string s;
	cin >> s;
	vector<int> res;
	res.clear();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			if (cnt > 0) {
				res.push_back(cnt);
			}
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	if (cnt > 0) {
		res.push_back(cnt);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i < res.size() - 1) {
			cout << res[i] << " ";
		}
		else {
			cout << res[i] << endl;
		}
	
	}
	
	return 0;
	
}