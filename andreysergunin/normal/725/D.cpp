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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;


struct team  {
	long long t;
	long long w;
};

bool operator < (const team &a, const team &b) {
	return a.t > b.t;
}

int main() {
	// freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;

	vector<team> t(n - 1);
	team d;
	cin >> d.t >> d.w;

	for (int i = 0; i < n - 1; ++i)
		cin >> t[i].t >> t[i].w;

	sort(all(t));
	t.push_back({0, 0});

	int ans = n;
	long long cur = 0;
	long long last = d.t;

	set<pair<long long, int>> s1, s2;

	for (int i = 0; i < n; ++i) {
		// cout << "!" << i << endl;
		int l = i + 1;
		if (t[i].t <= d.t) {
			cur += last - t[i].t;
			last = t[i].t;
			// cout << "?" << cur << endl;

			while (!s1.empty() && !s2.empty() && (--s1.end())->first > s2.begin()->first) {
				pair<long long, int> x = *(--s1.end());
				pair<long long, int> y = *s2.begin();
				// cout << x.first << " " << y.first << endl;
				cur += x.first - y.first;
				// cout << "." << cur << endl;
				s1.erase(x);
				s2.erase(y);
				s1.insert(y);
				s2.insert(x);
			}

			while (!s2.empty() && s2.begin()->first <= cur) {
				pair<long long, int> x = *s2.begin();
				cur -= x.first;
				// cout << x.first << endl;
				// cout << "." << cur << endl;
				s1.insert(x);
				s2.erase(x);
			}
			ans = min(ans, l - sz(s1));

			// cout << "!!!" << ans << endl;
		}

		
		s2.insert({t[i].w - t[i].t + 1, i});
		while (i < n && t[i].t == t[i + 1].t) {
			++i;
			s2.insert({t[i].w - t[i].t + 1, i});
		}
 	}
	cout << ans << endl;


	return 0;
}