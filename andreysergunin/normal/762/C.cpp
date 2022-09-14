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


const ll INF = 1e18;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	string s;
	string t;
	cin >> s >> t;


	vector<int> a(sz(s), -1);
	vector<int> b(sz(t), -1);

	int j = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (j < sz(t) && s[i] == t[j]) 
			++j;
		
		a[i] = j;
	}	

	// for (int i = 0; i < sz(s); ++i)
	// 	cout << a[i] << " ";
	// cout << endl;

	j = sz(t) - 1;
	for (int i = sz(s) - 1; i >= 0; --i) {
		if (s[i] == t[j]) {
			b[j] = i;
			--j;
			if (j == -1)
				break;
		}
	}

	// for (int i = 0; i < sz(t); ++i)
	// 	cout << b[i] << " ";
	// cout << endl;

	int ans = a[sz(s) - 1];
	int l = ans;
	int r = sz(t);
	if (ans == sz(t)) {
		cout << t << endl;
		return 0;
	}

	for (int i = 1; i < sz(t); ++i) {
		if (b[i] <= -1)
			continue;

		int k = b[i] - 1;
		int cur = (k >= 0 ? a[k] : 0) + sz(t) - i;
		if (ans < cur) {
			l = (k >= 0 ? a[k] : 0);
			r = i;
			ans = cur;
		}
	}
	t.erase(l, r - l);

	cout << (t == "" ? "-" : t) << endl;
	return 0;
}