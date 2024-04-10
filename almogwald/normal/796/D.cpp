//#include "stdafx.h"
#include <utility>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> point;
int main() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<vector<int>> tree(n+1);
	vector<point> pairs(n);
	vector<int> closest_to(n+1);
	queue<point> q;
	for (int i = 0; i < k; i++) {
		int s;
		cin >> s;
		q.push(make_pair(s, i));
	}
	closest_to[n] = -1;
	for (int i = 1; i<n; i++) {
		closest_to[i] = -1;
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		pairs[i] = make_pair(a, b);
	}
	while (!q.empty()) {
		point nr = q.front();
		int node = nr.first;
		int pol = nr.second;
		q.pop();
		if (closest_to[node] == -1) {
			closest_to[node] = pol;
			for (int i = 0; i < tree[node].size(); i++) {
				q.push(make_pair(tree[node][i], pol));
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i<n; i++) {
		if (closest_to[pairs[i].first] != closest_to[pairs[i].second]) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	/*cout << endl;
	for (int i = 0; i < n+1; i++) {
		cout << closest_to[i] << ' ';
	}
	cout << endl;*/
	return 0;
}