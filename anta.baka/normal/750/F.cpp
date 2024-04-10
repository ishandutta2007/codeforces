#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int h;
		cin >> h;
		int n = (1<<h) - 1;
		vector<vector<int>> g(n+1);
		vector<int> dep(n+1,-1);
		int deg;
		int ver;
		bool stop = false;

		cout << "? 1\n";
		cout.flush();
		cin >> deg;
		g[1].resize(deg);
		for(int i = 0; i < deg; i++)
			cin >> g[1][i];
		if(deg == 2) {
			cout << "! 1\n";
			cout.flush();
			continue;
		}
		int top = 1;
		vector<int> left_path;
		if(deg == 1) {
			dep[1] = h-1;
			left_path.push_back(1);
		}
		else {
			ver = g[1][0];
			vector<int> path1;
			path1.push_back(ver);
			while(true) {
				cout << "? " << ver << "\n";
				cout.flush();
				cin >> deg;
				g[ver].resize(deg);
				for(int i = 0; i < deg; i++)
					cin >> g[ver][i];
				if(deg == 2) {
					cout << "! " << ver << "\n";
					cout.flush();
					stop = true;
					break;
				}
				if(deg == 1)
					break;
				int next = g[ver][0];
				if(!g[next].empty())
					next = g[ver][1];
				ver = next;
				path1.push_back(ver);
			}
			if(stop)
				continue;
			ver = g[1][1];
			vector<int> path2;
			path2.push_back(ver);
			while(true) {
				cout << "? " << ver << "\n";
				cout.flush();
				cin >> deg;
				g[ver].resize(deg);
				for(int i = 0; i < deg; i++)
					cin >> g[ver][i];
				if(deg == 2) {
					cout << "! " << ver << "\n";
					cout.flush();
					stop = true;
					break;
				}
				if(deg == 1)
					break;
				int next = g[ver][0];
				if(!g[next].empty())
					next = g[ver][1];
				ver = next;
				path2.push_back(ver);
			}
			if(stop)
				continue;
			vector<int> leaf_to_leaf;
			for(int i = path1.size() - 1; i >= 0; i--)
				leaf_to_leaf.push_back(path1[i]);
			leaf_to_leaf.push_back(1);
			for(int i = 0; i < path2.size(); i++)
				leaf_to_leaf.push_back(path2[i]);
			int depth = h - 1;
			int l = 0, r = leaf_to_leaf.size() - 1;
			while(l <= r) {
				dep[leaf_to_leaf[l]] = depth;
				dep[leaf_to_leaf[r]] = depth;
				left_path.push_back(leaf_to_leaf[l]);
				top = leaf_to_leaf[l];
				l++; r--; depth--;
			}
		}
		for(int i = 0; i < g[top].size(); i++)
			if(dep[g[top][i]] == -1) {
				dep[g[top][i]] = dep[top] - 1;
				top = g[top][i];
				break;
			}
		while(dep[top] > 2) {
			cout << "? " << top << "\n";
			cout.flush();
			cin >> deg;
			g[top].resize(deg);
			for(int i = 0; i < deg; i++)
				cin >> g[top][i];
			int ver = g[top][0];
			if(!g[ver].empty())
				ver = g[top][1];
			vector<int> right_path;
			right_path.push_back(ver);
			while(true) {
				cout << "? " << ver << "\n";
				cout.flush();
				cin >> deg;
				g[ver].resize(deg);
				for(int i = 0; i < deg; i++)
					cin >> g[ver][i];
				if(deg == 2) {
					cout << "! " << ver << "\n";
					cout.flush();
					stop = true;
					break;
				}
				if(deg == 1)
					break;
				int next = g[ver][0];
				if(!g[next].empty())
					next = g[ver][1];
				ver = next;
				right_path.push_back(ver);
			}
			if(stop)
				break;
			vector<int> leaf_to_leaf;
			for(int i = 0; i < left_path.size(); i++)
				leaf_to_leaf.push_back(left_path[i]);
			leaf_to_leaf.push_back(top);
			for(int i = 0; i < right_path.size(); i++)
				leaf_to_leaf.push_back(right_path[i]);
			int l = 0, r = leaf_to_leaf.size() -  1;
			int depth = h - 1;
			left_path.clear();
			while(l <= r) {
				dep[leaf_to_leaf[l]] = depth;
				dep[leaf_to_leaf[r]] = depth;
				left_path.push_back(leaf_to_leaf[l]);
				top = leaf_to_leaf[l];
				l++; r--; depth--;
			}
			for(int i = 0; i < g[top].size(); i++)
				if(dep[g[top][i]] == -1) {
					dep[g[top][i]] = dep[top] - 1;
					top = g[top][i];
					break;
				}
		}
		if(stop)
			continue;
		queue<int> q;
		q.push(top);
		int cnt = 0;
		while(true) {
			int u = q.front();
			q.pop();
			if(cnt == 6) {
				cout << "! " << u << "\n";
				cout.flush();
				break;
			}
			cout << "? " << u << "\n";
			cout.flush();
			cnt++;
			cin >> deg;
			g[u].resize(deg);
			for(int i = 0; i < deg; i++) {
				cin >> g[u][i];
				if(dep[g[u][i]] == -1) {
					dep[g[u][i]] = 0;
					q.push(g[u][i]);
				}
			}
			if(deg == 2) {
				cout << "! " << u << "\n";
				cout.flush();
				break;
			}
		}
	}
	return 0;
}