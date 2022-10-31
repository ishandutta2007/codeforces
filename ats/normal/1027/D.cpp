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
vector<vector<int> >g;
int mn;
vector<int> V;
vector<int> C;
vector<int> path;
bool f;
int mk;
void dfs(int a) {
	V[a] = 0;
	path.push_back(a);
	for (int i = 0; i < g[a].size(); i++) {
		if (V[g[a][i]] == -1) {
			dfs(g[a][i]);
		}
		else if (V[g[a][i]] == 0) {
			f = false;
			mk = g[a][i];
		}
		if (!f)break;
	}
	V[a] = 1;
	if (!f)return;
	path.pop_back();

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	C.resize(N);
	int a;
	g.resize(N);
	V.resize(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		a--;
		g[i].push_back(a);
	}
	
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (V[i] == -1) {
			path.clear();
			f = true;
			dfs(i);
			if (!f) {
				int mn = 1 << 30;
				for (int j = (int)path.size() - 1; j >= 0; j--) {
					//cerr << path[j] + 1 << " ";
					mn = min(mn, C[path[j]]);
					if (path[j] == mk)break;
				}
				//cerr << endl;
				res += mn;
			}
		}
	}

	cout << res << endl;
}