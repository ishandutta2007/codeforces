#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool dfs(const int u, const vector<vector<int>> &adj, vector<int> &color, vector<int> &topo) {
	color[u] = 1;
	for (int v : adj[u])
		if (color[v] == 1 || (color[v] == 0 && !dfs(v, adj, color, topo)))
			return false;
	color[u] = 2;
	topo.push_back(u);
	return true;
}

void f() {
	int n;
	cin >> n;
	vector<int> nxt(n);
	for (int &x : nxt) {
		cin >> x;
		if (x != -1)
			x--;
	}

	vector<vector<int>> adj(n);

	{
		stack<int> st;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && nxt[st.top()] <= i)
				st.pop();
			if (!st.empty())
				adj[i].push_back(st.top());
			if (nxt[i] != -1) {
				if (nxt[i] < n)
					adj[i].push_back(nxt[i]);
				st.push(i);
			}
		}
	}

	vector<int> topo;

	{
		vector<int> color(n, 0);
		for (int i = 0; i < n; ++i)
			if (!color[i] && !dfs(i, adj, color, topo)) {
				cout << "-1\n";
				return;
			}
	}

	reverse(topo.begin(), topo.end());
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a[topo[i]] = i + 1;

	for (int &x : a)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--)
		f();
	return 0;
}

/*
 int f(const string s) {
 const int n = (int) s.size();
 for (int len = 1; len <= n; ++len) {
 map<string, int> occ;
 for (int i = 0; i + len <= n; ++i)
 ++occ[s.substr(i, len)];
 for (auto &&e : occ)
 if (e.second == 1)
 return len;
 }
 assert(false);
 return 0;
 }

 string toStr(const int mask, const int n) {
 string s;
 for (int i = 0; i < n; ++i)
 s += mask & (1 << i) ? '1' : '0';
 return s;
 }

 int popCnt(int x) {
 int res = 0;
 while (x & 1) {
 res++;
 x &= x - 1;
 }
 return res;
 }
 int main() {
 ios::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 const int n = 11;
 pair<int, int> res = { n + 1, 0 };
 for (int mask = 0; mask < (1 << n); ++mask) {
 const int k = f(toStr(mask, n));
 if (k == 7)
 res = min(res, { popCnt(mask), mask });
 }
 cout << toStr(res.second, n);

 return 0;
 }

 */