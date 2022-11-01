//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > icecreams(n + 1);
	int max_si = 0, max_si_node = 0;
	for (int i = 1; i <= n; ++i) {
		int si;
		cin >> si;
		if (si > max_si) {
			max_si = si;
			max_si_node = i;
		}
		icecreams[i].resize(si);
		for (int j = 0; j < si; ++j) {
			int c;
			cin >> c;
			icecreams[i][j] = c;
		}
	}
	vector<int> colors(m+1);
	vector<vector<int> > t(n + 1);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	if (max_si == 0) {
		cout << 1 << endl << 1;
		for (int i = 2; i <= m; i++) {
			cout << ' ' << 1;
		}
		return 0;
	}
	vector<int> visted(n + 1);
	vector<int> hascolors(max_si + 1);
	stack<int> nodes;
	nodes.push(max_si_node);
	while (!nodes.empty()) {
		int a = nodes.top();
		nodes.pop();
		if (visted[a] == 1) {
			continue;
		}
		visted[a] = 1;
		for (int i = 0; i < icecreams[a].size(); i++) {
			hascolors[colors[icecreams[a][i]]] = 1;
		}
		int color = 1;
		for (int i = 0; i < icecreams[a].size(); i++) {
			if (colors[icecreams[a][i]] == 0) {
				color++;
				colors[icecreams[a][i]] = color - 1;
				if (hascolors[color-1] == 1) {
					i--;
					colors[icecreams[a][i + 1]] = 0;
				}
			}
		}
		for (int i = 0; i < t[a].size(); i++) {
			nodes.push(t[a][i]);
		}
		for (int i = 0; i < icecreams[a].size(); i++) {
			hascolors[colors[icecreams[a][i]]] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (colors[i] == 0) {
			colors[i] = 1;
		}
	}
	cout << max_si << endl << colors[1];
	for (int i = 2; i <= m; i++) {
		cout << ' ' << colors[i];
	}
	cout << endl;
	/*int n, m, q;
	cin >> n >> m >> q;
	vector<int> joint(n + 1);
	set<int> * components = new set<int>[n + 1];

	for (int i = 0; i < n + 1; i++) {
		joint[i] = i;
		components[i].insert(i);
	}


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int size_a = components[joint[a]].size();
		int size_b = components[joint[b]].size();
		if (size_a <= size_b) {
			components[joint[b]].insert(components[joint[a]].begin(), components[joint[a]].end());
			components[joint[a]].clear();
			joint[a] = joint[b];
		}
		else {
			components[joint[a]].insert(components[joint[b]].begin(), components[joint[b]].end());
			components[joint[b]].clear();
			joint[b] = joint[a];
		}
	}
	
	for (int i = 1; i < n + 1; i++) {
		cout << i << " " << joint[i] << " " << components[joint[i]].size() << " " << (components[joint[i]].find(i) != components[joint[i]].end()) << endl;
	}*/


	return 0;
}