#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;
	int compCnt;

	DSU(int n) : compCnt(n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		compCnt--;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};


int n;
bool ans = false;
int M[1000][1000] = { 0 };


void f(int b) {
	if (n == 1) {
		ans = true;
		return;
	}
	if (n == 2) {
		if (b == 2) {
			ans = true;
			M[0][1] = M[1][0] = 1;
		}
		return;
	}
	if (n == 3) {
		if (b == 2) {
			ans = true;
			M[0][1] = M[1][0] = 1;
			M[0][2] = M[2][0] = 1;
		}
		else if (b == 3) {
			ans = true;
			M[0][1] = M[1][0] = 1;
			M[0][2] = M[2][0] = 1;
			M[1][2] = M[2][1] = 1;
		}
		return;
	}

	ans = true;
	for (int i = 0; i < n; ++i) {
		fill(M[i], M[i] + n, 1);
		M[i][i] = 0;
	}

	DSU dsu(n);
	for(int i = 0; i < n; ++i)
		for (int j = 0; j + 1 < i && dsu.compCnt != b; ++j) {
			M[i][j] = M[j][i] = 0;
			dsu.merge(i, j);
		}
	assert(dsu.compCnt == b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int a, b;
	cin >> n >> a >> b;
	if (a != 1 && b != 1) {
		cout << "NO";
		return 0;
	}

	if (a == 1) {
		f(b);
	}
	else {
		f(a);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j)
					M[i][j] ^= 1;
	}

	if (!ans)
		cout << "NO";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << M[i][j];
			cout << '\n';
		}
	}
	return 0;
}