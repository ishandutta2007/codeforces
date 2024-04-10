#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<int, int>> > graph;



int dfs(int v, int p) {
	int o = 0;
	int i = 0;

	for (pair<int, int>& u : graph[v]) {
		if (u.first == p) continue;
		int res = dfs(u.first, v);

		if (res == -1) return -1;
		if (res == 0) o++;
		if (res == 1) i++;
		u.second = res;

	}
	if (p == -1) {
		if (o - i == 0 || o - i == 1) {
			return 1;

		}
		else return -1;
	}

	if (o-i == 2 || o-i == 1) {
		return 1;
	}
	if (o - i == 0 || o - i == -1) {
		return 0;
	}
	return -1;
}

void dfs_output(int v, int p) {
	vector<int> o;
	vector<int> i;

	for (auto u : graph[v]) {
		if (u.first == p) continue;

		if (u.second == 0) o.push_back(u.first);
		if (u.second == 1) i.push_back(u.first);

	}
	if (p == -1) {
		for (int j = o.size()-1; j >=0 ; j--) {
			
			if(j < i.size()) dfs_output(i[j], v);
			dfs_output(o[j], v);
		}
		return;
	}

	if (o.size() - i.size() == 2 || o.size() - i.size() == 1) {
		if (o.size() - i.size() == 2) {
			dfs_output(o[0], v);
			cout << v + 1 << " " << p + 1 << endl;
			for (int j = 1; j < o.size(); j++) {
				dfs_output(o[j], v);
				if (j - 1 < i.size()) dfs_output(i[j - 1], v);

			}
		}
		else {
			cout << v + 1 << " " << p + 1 << endl;

			dfs_output(o[0], v);
			for (int j = 1; j < o.size(); j++) {
				if (j - 1 < i.size()) dfs_output(i[j - 1], v);

				dfs_output(o[j], v);

			}
		}
	}
	else {
		if (o.size() - i.size() == 0) {
			cout << v + 1 << " " << p + 1 << endl;
			for (int j = 0; j < i.size(); j++) {
				dfs_output(i[j], v);
				if (j < o.size()) dfs_output(o[j], v);

			}
		}
		else {
			dfs_output(i[0], v);
			cout << v + 1 << " " << p + 1 << endl;
			for (int j = 1; j < i.size(); j++) {
				dfs_output(i[j], v);
				if (j-1 < o.size()) dfs_output(o[j-1], v);

			}
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		 graph =  vector<vector<pair<int, int>> >(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			graph[x].push_back({ y, 0 });
			graph[y].push_back({ x, 0 });

		}
		if (dfs(0, -1) == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			dfs_output(0, -1);
		}
	}

}