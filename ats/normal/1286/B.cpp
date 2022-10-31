#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
vector<vector<int> > g;
vector<int> A;
bool ok = true;
vector<int> dfs(int a) {
	vector<int> res;
	for (int i : g[a]) {
		vector<int> X = dfs(i);
		for (int j : X) {
			res.push_back(j);
		}
	}
	if (A[a] > (int)res.size()) {
		ok = false;
		A[a] = (int)res.size();
	}
	vector<int> nres;
	for (int i = 0; i < A[a]; i++) {
		nres.push_back(res[i]);
	}
	nres.push_back(a);
	for (int i = A[a]; i < res.size(); i++) {
		nres.push_back(res[i]);
	}
	return nres;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	A.resize(N);
	int pa = 0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p >> A[i];
		p--;
		if (p != -1) {
			g[p].push_back(i);
		} else {
			pa = i;
			
		}
	}
	vector<int> t = dfs(pa);
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		res[t[i]] = i + 1;
	}
	if (ok) {
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			if (i > 0) cout << " ";
			cout << res[i];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}