#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <unordered_map>
#include <cassert>

#define ll long long
#define pii pair <int, int>
#define mp make_pair
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = 110;
char s[maxn][maxn];

vector <vector <pii> > ans;

int n, m;

void change(int x, int y) {
	s[x][y] = '0' + ('1' - s[x][y]);
}

void flip(int x, int y) {
	ans.push_back({});
	ans.back().push_back(mp(x, y));
	change(x, y);
	ans.back().push_back(mp(x - 1, y));
	change(x - 1, y);
	if (y) {
		ans.back().push_back(mp(x - 1, y - 1));
		change(x - 1, y - 1);
	} else {
		ans.back().push_back(mp(x - 1, y + 1));
		change(x - 1, y + 1);
	}
}

void flip1(int x, int y) {
	ans.push_back({});
	ans.back().push_back(mp(x, y));
	change(x, y);
	ans.back().push_back(mp(x, y - 1));
	change(x, y - 1);
	if (x) {
		ans.back().push_back(mp(x - 1, y - 1));
		change(x - 1, y - 1);
	} else {
		ans.back().push_back(mp(x + 1, y - 1));
		change(x + 1, y - 1);
	}
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		ans.clear();
		scanf("%d %d", &n, &m);
		
		for (int i = 0; i < n; i++) {
			scanf(" %s", s[i]);
			/*for (int j = 0; j < m; j++) {
				s[i][j] = '1';
			}*/
		}
		
		for (int i = n - 1; i >= 2; i--) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '1') {
					flip(i, j);
				}
			}
		}
		
		for (int j = m - 1; j >= 1; j--) {
			for (int i = 0; i < 2; i++) {
				if (s[i][j] == '1') {
					flip1(i, j);
				}
			}
		}
		
		if (s[0][0] == '1' && s[1][0] == '1') {
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(0, 1));
			ans.back().push_back(mp(1, 1));
			change(0, 0);
			change(0, 1);
			change(1, 1);
			ans.push_back({});
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(0, 1));
			ans.back().push_back(mp(1, 1));
			change(1, 0);
			change(0, 1);
			change(1, 1);
		} else if (s[0][0] == '1') {
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(0, 1));
			ans.back().push_back(mp(1, 1));
			change(0, 0);
			change(0, 1);
			change(1, 1);
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(1, 1));
			change(0, 0);
			change(1, 0);
			change(1, 1);
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(0, 1));
			change(0, 0);
			change(1, 0);
			change(0, 1);
		} else if (s[1][0] == '1') {
			ans.push_back({});
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(0, 1));
			ans.back().push_back(mp(1, 1));
			change(1, 0);
			change(0, 1);
			change(1, 1);
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(1, 1));
			change(0, 0);
			change(1, 0);
			change(1, 1);
			ans.push_back({});
			ans.back().push_back(mp(0, 0));
			ans.back().push_back(mp(1, 0));
			ans.back().push_back(mp(0, 1));
			change(0, 0);
			change(1, 0);
			change(0, 1);
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '1') {
					assert(false);
				}
			}
		}
		
		sort(ans.begin(), ans.end());
		vector <vector <pii> > res;
		
		//assert((int)ans.size() <= n * m);
		
		/*for (int i = 0; i < (int)ans.size(); i++) {
			if (i < (int)ans.size() && ans[i] == ans[i + 1]) {
				i++;
				continue;
			}
			res.push_back(ans[i]);
		}*/
		
		//ans = res;

		cout << ans.size() << '\n';
		
		for (auto f : ans) {
			for (auto p : f) {
				printf("%d %d ", p.first + 1, p.second + 1);
			}
			printf("\n");
		}
	}
}