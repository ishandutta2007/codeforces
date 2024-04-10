#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int n, m, p;
int need = 0;

vector<vector<int>> v;

vector<pair<int,int>> o;

int cnt = 0;
vector<int> ans;

int fcnt = 0;
vector<int> fans;

void work(int d, vector<int> cur) {
	if (m - d + cnt <= fcnt)
		return;
	if (cnt == p || d == m) {
		if (cnt > fcnt) {
			fcnt = cnt;
			fans = ans;
		}
		return;
	}
	vector<int> cur2;
	for (int i : cur)
		if (v[i][o[d].second])
			cur2.push_back(i);
	cnt++;
	ans[o[d].second] = 1;
	if (cur2.size() >= need)
		work(d + 1, cur2);
	cnt--;
	ans[o[d].second] = 0;
	if (cur2.size() != cur.size())
		work(d + 1, cur);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> p;
	need = (n - 1) / 2 + 1;
	v = vector<vector<int>> (n, vector<int> (m));
	fans = ans = vector<int> (m);

	vector<int> cnt(m);
	char c;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j) {
		cin >> c;
		v[i][j] = (c == '1');
		if (v[i][j]) cnt[j]++;
	}

	vector<int> all;
	for (int i = 0; i < n; ++i)
		all.push_back(i);

	for (int i = 0; i < m; ++i)
		o.push_back({cnt[i], i});
	
	// std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(o.begin(), o.end(), g);
 	sort(o.begin(), o.end());

	work(0, all);
	for (int i : fans)
		cout << i;
	cout << endl;
	return 0;
}