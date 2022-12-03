#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;

set<string> vis;

void dfs(string s) {
	if (vis.count(s)) return;
	vis.insert(s);
	string s1 = {s[1], s[2], s[3], s[0], s[4], s[5]};
	dfs(s1);
	string s2 = {s[0], s[4], s[2], s[5], s[3], s[1]};
	dfs(s2);
}

string s;

int main() {
	int ans = 0;
	cin >> s;
	sort(s.begin(), s.end());
	do {
		if (vis.count(s)) continue;
		ans++;
		dfs(s);
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
	return 0;
}