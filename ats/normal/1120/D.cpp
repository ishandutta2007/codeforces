#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<vector<int> > g;
vector<int> A;
const int INF = (int)1 << 50;
vector< vector<int> > mni;
vector<int> du;
vector<int> use;
pair<int, int> dfs(int a, int p = -1) {

	pair<int, int> pa;
	int sum = 0;
	int mn = INF;

	for (int i : g[a]) {
		if (i != p) {
			pa = dfs(i, a);
			sum += pa.first;
			if (mn > pa.second - pa.first) {
				mn = pa.second - pa.first;
				mni[a].clear();
				mni[a].push_back(i);
			}
			else if (mn == pa.second - pa.first) {
				mni[a].push_back(i);
			}
		}
	}

	pair<int, int> res;
	if (mn == INF) {
		res.second = 0;
		res.first = A[a];
		use[a] = 1;
	}
	else {
		res.second = sum + mn;
		res.first = min(sum, sum + mn + A[a]);
		if (sum > sum + mn + A[a]) {
			use[a] = 1;
		}
		else if (sum == sum + mn + A[a]) {
			use[a] = 2;
		}
	}

	//cerr << a << " " << res.first << " " << res.second << endl;
	return res;
}

vector<int> st;
vector<vector<int> > memo;
void dfs2(int a, int t, int p = -1) {

	if (memo[a][t] != -1)return;
	memo[a][t] = 0;
	set<int> m;
	int d = 0;
	int xx = -1;
	if (t == 0) {
		if (use[a] == 1) {
			for (int i = 0; i < mni[a].size(); i++)m.insert(mni[a][i]);
			st.push_back(a);
		}
		else if (use[a] == 2) {
			for (int i = 0; i < mni[a].size(); i++)m.insert(mni[a][i]);
			st.push_back(a);
			xx = 1;
		}
	}
	else {
		for (int i = 0; i < mni[a].size(); i++)m.insert(mni[a][i]);
	}
	for (int i : g[a]) {
		if (i != p) {
			if (m.count(i) > 0) {
				dfs2(i, 1, a);
				if ((int)m.size() > 1 || xx == 1) {
					dfs2(i, 0, a);
				}
			}
			else {
				dfs2(i, 0, a);
			}
		}
	}

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	A.resize(N);
	g.resize(N);
	mni.resize(N);
	use.resize(N, 0);
	memo.resize(N, vector<int>(2, -1));
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	res = dfs(0).first;

	dfs2(0, 0);


	sort(st.begin(), st.end());

	st.erase(unique(st.begin(), st.end()), st.end());


	cout << res << " " << st.size() << endl;
	for (int i = 0; i < st.size(); i++) {
		if (i > 0)cout << " ";
		cout << st[i] + 1;
	}

	cout << endl;
}