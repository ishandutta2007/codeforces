#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
	for (auto &el : arr) {
		in >> el;
	}
	return in;
}


template<typename T, typename TT>
istream &operator>>(istream &in, pair<T, TT> &pp) {
	in >> pp.first >> pp.second;
	return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
	for (auto &el : arr) {
		out << el << " ";
	}
	return out;
}

template<typename T, typename TT>
ostream &operator<<(ostream &out, pair<T, TT> pp) {
	out << pp.first << " " << pp.second;
	return out;
}

vector<vector<vector<int>>> g;
vector<int> used;
int timer = 2;

bool dfs(int gg, int u) {
	used[u] = timer;	
	for (int v : g[gg][u]) {
		if (used[v] == timer) {
			return true;
		} else if (used[v] != timer + 1) {
			if (dfs(gg, v)) {
				return true;
			}
		}
	}
	used[u] = timer + 1;
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(1, vector<vector<int>> (n));
	used.resize(n);
	vector<int> color(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int ind = 0;
		while (true) {
			if (g.size() == ind) {
				g.push_back(vector<vector<int>> (n));
			}
			g[ind][a].push_back(b);
			if (dfs(ind, a)) {
				timer += 3;
				g[ind][a].pop_back();
				ind++;
			} else {
				timer += 3;
				break;
			}
		}
		color[i] = ind + 1;
	}
	cout << g.size() << endl;
	cout << color << endl;
}