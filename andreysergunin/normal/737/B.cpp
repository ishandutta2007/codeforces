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
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;    

struct Car {
	ll c;
	ll v;
};

bool operator < (const Car &a, const Car &b) {
	return a.v < b.v;
}

const ll INF = 1e10;

int main() {
	ios_base::sync_with_stdio(0);

	 int n, a, b, k;
	cin >> n >> b >> a >> k;
	string s;
	cin >> s;

	vector<int> l;
	int prev = -1;

	for (int i = 0; i <= n; ++i) {
		if (i == n || s[i] == '1') {
			l.push_back(i - prev - 1);
			prev = i;
		}
	}

	int mx = 0;
	for (int i = 0; i < sz(l); ++i)
		mx += l[i] / a;

	int ans = mx - b + 1;
	cout << ans << endl;

	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			cur = 0;
		} else {
			++cur;
			if (cur == a && ans) {
				cout << i + 1 << " ";
				--ans;
				cur = 0;
			}
		}
	}
	cout << endl;
	return 0;
}