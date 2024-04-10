#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

vector<vector<int> > g;
vector<int> resA;
vector<int> resB;
int cur = 0;
void dfs(int a, int p = -1) {
	vector<int> X;
	for (const int &i : g[a]) {
		if (i != p) {
			X.push_back(i);
			resA[i] = cur;
			cur++;
		}
	}
	resB[a] = cur;
	cur++;
	reverse(X.begin(), X.end());
	for (const int &i : X) {
		dfs(i, a);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	resA.resize(N);
	resB.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	resA[0] = cur;
	cur++;
	dfs(0);
	for (int i = 0; i < N; i++) {
		cout << resA[i] + 1 << " " << resB[i] + 1 << "\n";
	}
	return 0;
}