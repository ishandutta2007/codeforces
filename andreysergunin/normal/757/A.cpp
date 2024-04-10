#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	vector<int> cnt(256);

	for (int i = 0; i < sz(s); ++i) {
		++cnt[s[i]];
	}

	int ans = sz(s);
	// Bulbasaur
	ans = min(ans, cnt['B']);
	ans = min(ans, cnt['u'] / 2);
	ans = min(ans, cnt['l']);
	ans = min(ans, cnt['b']);
	ans = min(ans, cnt['a'] / 2);
	ans = min(ans, cnt['s']);
	ans = min(ans, cnt['r']);

	cout << ans << endl;



}