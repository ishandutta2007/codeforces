#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
struct V {
	int a[26];
	int from;
	int type = 1;
	V() {
		for (int i = 0; i < 26; i++) {
			a[i] = -1;
		}
	}
};
vector<V> vs;
int res;
int tc;
vector<vector<int > >g;
vector<int >v;

vector<int>dp0;
vector<int>dp1;

int dfs(int x) {
	int ret = 1;
	dp0[x] = 0;
	dp1[x] = 1;
	v[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		if (v[g[x][i]] == 0) {
			ret+=dfs(g[x][i]);
			dp0[x] += max(dp0[g[x][i]], dp1[g[x][i]]);
			dp1[x] += dp0[g[x][i]];
		}
	}
	return ret;
}
vector<string> ss;
signed main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	V tmp;
	tmp.from = -1;
	for (int i = 0; i < 26; i++) {
		tmp.a[i] = -1;
	}
	while (t--) {
		int N;
		cin >> N;
		ss.clear();
		ss.resize(N);
		g.clear();
		v.clear();
		dp1.clear();
		dp0.clear();
		for (int i = 0; i < N; i++) {
			cin >> ss[i];
		}
		int cur;
		int cur2;
		vs.clear();
		vs.push_back(tmp);
		for (int i = 0; i < N; i++) {
			cur = 0;
			for (int j = 0; j < ss[i].size(); j++) {
				if (vs[cur].a[(int)(ss[i][j] - 'a')] == -1) {
					vs[cur].a[(int)(ss[i][j] - 'a')] = (int)vs.size();
					tmp.from = cur;
					cur = vs.size();
					vs.push_back(tmp);
				}
				else {
					cur = vs[cur].a[(int)(ss[i][j] - 'a')];
				}
			}
		}
		g.resize(vs.size());
		v.resize(vs.size(), 0);
		dp0.resize(vs.size());
		dp1.resize(vs.size(), 0);
		for (int i = 0; i < N; i++) {
			cur = 0;
			cur2 = 0;
			for (int j = 0; j < ss[i].size(); j++) {

				cur = vs[cur].a[(int)(ss[i][j] - 'a')];

				if (j > 0 && (cur2 >= 0)) {
					if (vs[cur2].a[(int)(ss[i][j] - 'a')] == -1) {
						cur2 = -1;
					}
					else {
						cur2 = vs[cur2].a[(int)(ss[i][j] - 'a')];
						g[cur2].push_back(cur);
						g[cur].push_back(cur2);
					}
				}
			}
		}
		v[0] = 1;
		int tt;
		res = 0;
		for (int i = 1; i < vs.size(); i++) {

			if (v[i] == 0) {
				
				tt=dfs(i);
				res += max(dp0[i], dp1[i]);
				//cerr << i << " " << tc << " " << tt << endl;
			}

		}
		cout << res << endl;
	}
}