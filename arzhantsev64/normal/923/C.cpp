#include <bits/stdc++.h>

using namespace std;

vector<int> w(1);
vector<vector<int>> g(1, vector<int> (2, -1));

void add(const int s) {
	int v = 0;
	w[v]++;
	for (int  i = 30; i >= 0; --i) {
		int u = g[v][(s >> i) & 1];
		if (u == -1) {
			w.push_back(0);
			g.push_back(vector<int> (2, -1));
			g[v][(s >> i) & 1] = g.size() - 1;
		}
		v = g[v][(s >> i) & 1];
		w[v]++;
	}
}

int get(const int s) {
	int v = 0;
	w[v]--;
	int cur = 0;
	for (int  i = 30; i >= 0; --i) {
		int bit = (s >> i) & 1; 
		int r = v;
		v = g[v][bit];
		if (v == -1 || w[v] == 0) {
			v = g[r][bit ^ 1];
			cur |= ((bit ^ 1) << i);
		} else {
			cur |= (bit << i);
		}
		w[v]--;
		// cout << cur << ' ';
	}
	return s ^ cur;
}

int main() {
	int n;
	cin >> n;
	vector<int> words(n);
	vector<int> keys(n);
	for (int i = 0; i < n; ++i) cin >> words[i];
	for (int i = 0; i < n; ++i) cin >> keys[i];
	for (auto i : keys) add(i);
	for (auto i : words) cout << get(i) << ' ';
}