#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
vector<int> used;
vector<int> ne;
int N, K;
int dfs(int a,bool f) {
	if (a >= N) return -1;
	if (used[a] == 0) {
		if (f) {
			used[a] = 1;
			ne[a] = dfs(a + 1, false);
		}
		return a;
	}
	ne[a] = dfs(ne[a], f);
	return ne[a];
}
signed main() {
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	//N = 300000;
	//K = 10;
	used.resize(N, 0);
	ne.resize(N, 0);

	vector<int> C(N);
	vector<pair<int, int> > vp(N);
	for (int i = 0; i < N; i++) {
		cin >> vp[i].first;
		//vp[i].first = i;
		C[i] = vp[i].first;
		vp[i].second = i;
	}
	sort(vp.begin(), vp.end());
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		ne[i] = i;
	}
	int p;
	
	for (int i = 0; i < N; i++) {
		//if (i % 100 == 0) cerr << "A" << endl;
		p = vp[N - 1 - i].second;
		
		res[p] = dfs(max((int)0, p - K),true) + K;
		
	}
	int cost = 0;
	for (int i = 0; i < N; i++) {
		cost += abs(i - res[i])*C[i];
	}
	cout << cost << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << (res[i] + 1);
	}
	cout << endl;
}