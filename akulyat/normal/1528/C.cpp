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

int n;
vector<vector<int>> kids1, kids2;
bool viv = false;

void read(vector<vector<int>> &kids) {
	kids.assign(n, {});
	for (int i = 1; i < n; i++) {
		int par;
		cin >> par;
		par--;
		kids[par].push_back(i);
	}
}

vector<int> tin, tout;
int t;
void DFS2(int v) {
	tin[v] = t++;
	for (auto u : kids2[v])
		DFS2(u);
	tout[v] = t++;
}
void get_tin_tout() {
	tin.assign(n, -1);
	tout.assign(n, -1);
	int t = 0;
	DFS2(0);
}


set<pii> st;
const pii emp = {-1, -1};
pii adder(int v) {
	pii p = {tin[v], v};
	auto z = st.lower_bound(p);
	if (z != st.end() && (z->F) < tout[v]) 
		return emp;
	if (z == st.begin()) {
		st.insert(p);
		return emp;
	}
	z--;
	if (tout[z->S] < tin[v]) {
		st.insert(p);
		return emp;
	}	
	pii res = *z;
	st.insert(p);
	st.erase(res);
	return res;
}

int ans;
void DFS(int v) {
	pii p = {tin[v], v};
	pii add = adder(v);	

	ans = max(ans, (int)st.size());
	if (viv) {
		cout << "DFS(" << v << ")" << endl;
		cout << "\tst = ";
		for (auto p : st)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}
	for (auto u : kids1[v])
		DFS(u);

	st.erase(p);
	if (add != emp) {
		st.insert(add);
	}
}

void solver() {
	ans = 0;
	DFS(0);
	cout << ans << '\n';
}

void solve() {
	cin >> n;
	read(kids1);
	read(kids2);
	get_tin_tout();
	solver();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}