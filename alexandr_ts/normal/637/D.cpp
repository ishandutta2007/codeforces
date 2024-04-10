#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <deque>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <numeric>
#include <assert.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main() {
	//ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<int> a;
	a.push_back(0);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	a.push_back(1e9 + 1e9 + 1e4);
	sort(a.begin(), a.end());
	vector<string> ans1;
	vector<int> ans2;
	int cur = 1, nxt = 1, temp = 0;
	while (cur < (int)a.size() - 1) {
		if (a[cur] - temp - 1 < s) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		ans1.push_back("RUN");
		ans2.push_back(a[cur] - temp - 1);
		temp = a[cur] - 1;
		nxt = cur;
		while (a[nxt + 1] - a[nxt] - 2 < s)
			nxt++;
		ans1.push_back("JUMP");
		ans2.push_back(a[nxt] + 1 - temp);
		if (a[nxt] + 1 - temp > d) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		temp = a[nxt] + 1;
		cur = nxt + 1;
	}
	if (temp != m) {
		ans1.push_back("RUN");
		ans2.push_back(m - temp);
	}
	for (int i = 0; i < (int)ans1.size(); i++) {
		cout << ans1[i] << " ";
		printf("%d\n", ans2[i]);
	}
	return 0;
}