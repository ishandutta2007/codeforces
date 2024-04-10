#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, ans;
vector<int> ans_res;
vector<vector<pii>> e;
bool viv = false;



vector<int> col;
void DFS0(int v, int c) {
	col[v] = c;
	for (auto p : e[v]) {
		int u = p.F;
		if (col[u] == -1)
			DFS0(u, c ^ 1);
		else {
			if (col[u] == col[v]) {
				cout << "NO";
				exit(0);
			}
		}
	}
}

void stpd() {
	col.resize(n, -1);
	DFS0(0, 0);
}

vector<pii> pcol;
vector<vector<int>> gr;
void DFS1(int v, pii pr) {
	pcol[v] = pr;
	gr[pr.F].push_back(v); 
	for (auto ee : e[v]) {
		int u = ee.F;
		int tp = ee.S;
		if (tp && pcol[u].F == -1)
			DFS1(u, {pr.F, pr.S + tp});
	}
}

void prepare() {
	pcol.resize(n, {-1, 0});
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (pcol[i].F == -1) {
			gr.push_back({});
			DFS1(i, {cc, 0});
			cc++;
		}
	}
	for (auto &line : gr) {
		for (int i = 0; i < line.size(); i++)
			if (pcol[line[0]].S > pcol[line[i]].S)
				swap(line[0], line[i]);
		for (int i = 1; i < line.size(); i++)
			pcol[line[i]].S -= pcol[line[0]].S;
		pcol[line[0]].S = 0;

		if (viv) {
			cout << "line: ";
			for (auto i : line)
				cout << i << ' ';
			cout << '\n';
		}
	}

}

vector<bool> used;
vector<pii> seg;
void DFS(int v) {
	used[v] = false;
	for (auto p : e[v]) {
		int u = p.F;
		int tp = p.F;
		if (used[u]) {
			tp = -tp;
			swap(u, v);
			if (tp) {
				seg[u].F = max(seg[u].F, seg[v].F + tp);
				seg[u].S = max(seg[u].S, seg[v].S + tp);
			} else {
				seg[u].F = max(seg[u].F, seg[v].F - 1);
				seg[u].S = max(seg[u].S, seg[v].S + 1);
			}
			tp = -tp;
			swap(u, v);
		} else {
			if (tp) {
				seg[u].F = max(seg[u].F, seg[v].F + tp);
				seg[u].S = max(seg[u].S, seg[v].S + tp);
			} else {
				seg[u].F = max(seg[u].F, seg[v].F - 1);
				seg[u].S = max(seg[u].S, seg[v].S + 1);
			}
			DFS(u);
		}
	}
}

void work() {
	for (int i = 1; i < gr.size(); i++)
		swap(gr[i - 1], gr[i]);
	for (auto &pr : pcol) {
		pr.F += ((int)gr.size() - 1);
		pr.F %= (int)(gr.size());
	}
	if (viv) {
		cout << "work now: " << endl;;
		for (auto line : gr) {
			cout << "\tl:";
			for (auto i : line)
				cout << i << ' ';
			cout << endl;
		}
		cout << endl;
		for (auto pr : pcol) {
			cout << "\t\t" << pr.F << ' ' << pr.S << '\n';
		}
	}
	vector<int> add(gr.size(), mod);
	add[0] = 0;
	for (int j = 0; j < 50; j++) {
		for (int i = 0; i < gr.size(); i++) {
			auto line = gr[i];
			for (auto v : line) {
				for (auto ee : e[v]) {
					int u = ee.F;
					if (pcol[u].F > pcol[v].F) {
						add[pcol[u].F] = min(add[pcol[u].F], add[pcol[v].F] - (pcol[u].S - pcol[v].S - 1));
					}
				}
			}
		}
		for (int i = gr.size() - 1; i >= 0; i--) {
			auto line = gr[i];
			for (auto v : line) {
				for (auto ee : e[v]) {
					int u = ee.F;
					if (pcol[u].F < pcol[v].F) {
						add[pcol[u].F] = min(add[pcol[u].F], add[pcol[v].F] - (pcol[u].S - pcol[v].S - 1));
					}
				}
			}
		}
	}
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		res[i] = pcol[i].S + add[pcol[i].F];
	if (viv) {
		cout << "try: ";
		for (auto i : res)
			cout << i << ' ';
		cout << endl;
		cout << "add: ";
		for (auto i : add)
			cout << i << ' ';
		cout << endl;
	}
	bool norm = true;
	for (int v = 0; v < n; v++) {
		for (auto ee : e[v]) {
			int u = ee.F;
			int tp = ee.S;
			if (tp) {
				if (res[u] - res[v] != tp)
					norm = false;
			} else {
				if (abs(res[u] - res[v]) != 1)
					norm = false;
			}
		}
	}
	if (norm) {
		int mn = mod;
		for (auto i : res)
			mn = min(mn, i);
		for (auto &i : res)
			i -= mn;
		int mx = 0;
		for (auto i : res)
			mx = max(mx, i);
		if (mx > ans) {
			ans = mx;
			ans_res = res;
		}
	}
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, -c});
	}
	// stpd();	
	if (viv)
		cout << "no bad cycles" << endl;
	prepare();
	ans = -mod;
	for (int i = 0; i < gr.size(); i++)
		work();
	if (ans == -mod) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans << '\n';
		for (auto i : ans_res)
			cout << i << ' ';
		cout << '\n';		
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}