#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

vector<int> t[maxn];
vector<int> eulerTour;

void dfs(int v, int par = -1) {
	eulerTour.push_back(v);
	for (auto u : t[v])
		if (u != par) {
			dfs(u, v);
			eulerTour.push_back(v);
		}
}

int ask(int lo, int hi) {
	set<int> S;
	for (int i = lo; i <= hi; i++)
		S.insert(eulerTour[i]);
	cout << "? ";
	cout << S.size() << " ";
	for (auto it : S)
		cout << it << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}

void solveOne() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		t[i].clear();
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	eulerTour.clear();
	dfs(1);
	int maxEdge = ask(0, eulerTour.size() - 1);
	int lo = 0, hi = eulerTour.size() - 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (ask(lo, mid) == maxEdge)
			hi = mid;
		else
			lo = mid;
	}
	cout << "! " << eulerTour[lo] << " " << eulerTour[hi] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}