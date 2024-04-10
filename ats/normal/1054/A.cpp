#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int s = abs(x - y)*t1;
	int e = t2*(abs(x - z) + abs(x - y)) + 3 * t3;
	//cerr << s << " " << e << endl;
	if (s < e) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}