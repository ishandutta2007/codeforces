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
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	UnionFind uf(N);
	int t, a, b;
	set<int> st;
	for (int i = 0; i < N; i++) {
		st.insert(i);
	}
	for (int i = 0; i < Q; i++) {
		cin >> t >> a >> b; a--; b--;
		if (t == 1) {
			uf.unionSet(a, b);
		}
		else if (t == 2) {
			auto x = st.find(a);
			if(x == st.end()){
				st.insert(a);
				x = st.find(a);
				x++;
			}
			while (x != st.end() && (*x) < b) {
				uf.unionSet((*x), (*x) + 1);
				x = st.erase(x);
			}

			//st.erase(a);
		}
		else {
			if (uf.findSet(a, b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

}