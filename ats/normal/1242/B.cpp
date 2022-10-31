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

struct FastSet {
	vector<int> list;
	vector<int> pos;
	void init(int N) {
		pos.resize(N, -1);
		list.reserve(N);
	}
	void insert_all() {
		list.clear();
		list.resize(pos.size());
		for (int i = 0; i < list.size(); i++) {
			pos[i] = list[i] = i;
		}
	}
	void insert(int a) {
		if (pos[a] == -1) {
			pos[a] = list.size();
			list.push_back(a);
		}
	}
	void erase(int a) {
		if (pos[a] >= 0) {
			swap(list[pos[a]], list.back());
			pos[list[pos[a]]] = pos[a];
			pos[a] = -1;
			list.pop_back();
		}
	}
	void flip(int a) {
		if (pos[a] == -1) {
			pos[a] = list.size();
			list.push_back(a);
		}
		else {
			swap(list[pos[a]], list.back());
			pos[list[pos[a]]] = pos[a];
			pos[a] = -1;
			list.pop_back();
		}
	}
	inline int size() {
		return list.size();
	}
	inline void erase_all() {
		for (int i : list) {
			pos[i] = -1;
		}
		list.clear();
	}
};

int res;
vector<set<int > >g;
FastSet fs;
vector<int> V;
void dfs(int a) {
	//cerr << a << endl;
	fs.erase(a);
	V[a] = 1;
	vector<int> X;
	vector<int> Y = fs.list;
	for (int i : Y) {
		if (g[a].count(i) == 0) {
			X.push_back(i);
			fs.erase(i);
		}
	}
	for (int i : X) {
		dfs(i);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int a, b;
	fs.init(N);
	fs.insert_all();
	g.resize(N);
	V.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}

	res = -1;

	for (int i = 0; i < N; i++) {
		if (V[i] == 0) {
			res++;
			dfs(i);
		}
	}


	cout << res << endl;
}