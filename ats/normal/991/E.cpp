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
vector<int> X;
vector<int> V;
int ans;
int p[20];
void dfs(int a) {
	if (a == 10) {
	/*	cerr << endl;
		for (int i = 0; i < X.size(); i++) {
			cerr << X[i] << " ";
		}
		cerr << endl;*/
		int sum = 0;
		for (int i = 0; i < X.size(); i++) {
			sum += X[i];
		}
		int t = p[sum];
		for (int i = 0; i < X.size(); i++) {
			t /= p[X[i]];
		}
		ans += t;
		//cerr << t << endl;
		return;
	}
	if (V[a] == 0) {
		dfs(a + 1);
	}
	else {
		for (int i = 1; i <= V[a]; i++) {
			X.push_back(i);
			dfs(a + 1);
			X.pop_back();
		}
	}
}
int cnt() {
	X.clear();
	ans = 0;
	dfs(0);
	return ans;
}
void f(int N) {
	V.clear();
	V.resize(10, 0);
	while (N > 0) {
		V[N % 10]++;
		N /= 10;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	f(N);
	/*for (int i = 0; i < 10; i++) {
		cerr << V[i] << endl;
	}*/
	p[0] = 1;
	for (int i = 1; i <= 19; i++) {
		p[i] = p[i - 1] * i;
	}
	int res = cnt();

	if (V[0] == 1) {
		V[0] = 0;
		res -= cnt();
	}
	else if (V[0] > 1) {
		V[0]--;
		res -= cnt();
		V[0] = 0;
		res -= cnt();
	}
	cout << res << endl;
}