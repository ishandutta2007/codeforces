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

	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		vector<int> d(n);
		for (int i = 0; i < n; i++) cin >> d[i];

		int cur = 0;
		vector<int> used(n, 0);
		while (1) {
			if (cur < 0 || cur >= n) {
				cout << "FINITE" << endl;
				break;
			}
			if (used[cur]) {
				cout << "INFINITE" << endl;
				break;
			}
			used[cur] = 1;
			if (s[cur] == '>') cur += d[cur];
			else cur -= d[cur];
		}
	}

	return 0;
}