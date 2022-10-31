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
vector<vector<int> > g;
vector<int> A;
vector<int> B;
int res = 0;
bool ok = true;
void dfs(int a, int sum) {
	if (A[a] == -1) {
		int mn = (int)1 << 60;
		for (auto i : g[a]) {
			mn = min(mn, A[i] - sum);
		}
		if (mn < 0)ok = false;
		if (mn == (int)1 << 60)mn = 0;
		B[a] = mn;
	}
	else {
		B[a] = A[a] - sum;
	}
	for (auto i : g[a]) {
		dfs(i, sum + B[a]);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	int res = 0;
	int a;
	for (int i = 0; i < N - 1; i++) {
		cin >> a; a--;
		g[a].push_back(i + 1);
	}
	A.resize(N);
	B.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dfs(0, 0);
	for (int i = 0; i < N; i++) {
		res += B[i];
		//cerr << B[i] << " ";
	}
	//cerr << endl;
	if (ok) {
		cout << res << endl;
	}
	else {
		cout << -1 << endl;
	}
}