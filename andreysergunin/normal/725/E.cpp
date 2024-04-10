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
              
const int INF = 1e9;

int main() {
	// freopen("input.txt", "r", stdin);
		
	int c, n;
	scanf("%d %d", &c, &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	sort(all(a));
	
	vector<long long> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) 
		pref[i + 1] = pref[i] + a[i];

	vector<pair<long long, int>> queries;

	int x = c;
	int y = c;

	for (int i = n - 1; i >= 1; --i) {
		if (x >= a[i]) {
			for (int j = a[i] + 1; j <= y; ++j) {
				queries.push_back({pref[i + 1] - (x - j), j});
			}
			x -= a[i];
			y = min(a[i], x);
		}
	}

	sort(all(queries));
	reverse(all(queries));

	vector<vector<int>> v(c + 1);

	set<int> s;

	int cur = 0;
	for (int i = n; i > 0; --i) {

		while (cur < sz(queries) && queries[cur].first > pref[i - 1]) {
			int t = pref[i] - queries[cur].first; 
			s.insert(t);
			v[t].push_back(queries[cur].second);
			++cur;
		}
		if (i > 1) {
			long long d = pref[i - 1] - pref[i - 2];
			while (!s.empty() && *(--s.end()) >= d) {
				long long x = *(--s.end());
				s.erase(x);
				long long y = pref[i - 1] - x;
				if (y < 0) 
					continue;

				long long z = *lower_bound(pref.begin(), pref.end(), y);
				y = z - y;
				s.insert(y);

				if (sz(v[x]) > sz(v[y]))
					swap(v[x], v[y]);

				for (int j = 0; j < sz(v[x]); ++j) 
					v[y].push_back(v[x][j]);
				
				v[x].clear();
			}
		}
	}
	
	int ans = INF;
	for (int i = 1; i < sz(v); ++i)
		for (int j = 0; j < sz(v[i]); ++j)
			ans = min(ans, v[i][j]);

	if (ans == INF) 
		cout << "Greed is good" << endl;
	else 
		cout << ans << endl;

	return 0;
}