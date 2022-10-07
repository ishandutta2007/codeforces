#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (cin >> n >> k) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (n == 4 || k <= n) {
			cout << -1 << endl;
			continue;
		}
		vector<int> vct;
		for (int i = 1; i <= n; i++) {
			if (i == a || i == b || i == c || i == d) continue;
			vct.push_back(i);
		}

		cout << a << " " << c << " ";
		for (int i = 0; i < (int)vct.size(); i++) cout << vct[i] << " ";
		cout << d << " " << b << endl;

		cout << c << " " << a << " ";
		for (int i = (int)vct.size() - 1; i >= 0; i--) cout << vct[i] << " ";
		cout << b << " " << d << endl;
	}

	return 0;
}