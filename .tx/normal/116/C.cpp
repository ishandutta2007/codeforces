#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector< vector<int> > gr;
vector<bool> used;
int mmax;

void dfs(int v, int d) {
	used[v] = true;
	mmax = max(mmax, d);
	for (vector<int>::iterator it = gr[v].begin(); it != gr[v].end(); it++) {
		if (!used[*it]) {
			dfs(*it, d + 1);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	gr.resize(n);
	used.assign(n, false);
	int x;
	vector<bool> a(n, false);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != -1) {
			gr[--x].push_back(i);
			gr[i].push_back(x);
		}
		else {
			a[i] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			dfs(i, 1);
		}
	}
	cout << mmax;




	return 0;
}//ywaeae