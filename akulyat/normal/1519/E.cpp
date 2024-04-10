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

ll n;
vector<vector<int>> v;
vector<pii> ans;
vector<bool> used;
bool viv = false;

void read(vector<int> &l) {
	l.resize(4);
	for (auto &i : l)
		cin >> i;
}

void ch(int &a, int &b) {
	int g = __gcd(a, b);
	a /= g;
	b /= g;
}

vector<set<int>> e;
map<vector<ll>, int> nums;
map<pii, vector<int>> inp;
int num(int a, int b, int c, int d) {
	ch(a, b);
	ch(c, d);
	pll p = {(ll)a * d, (ll)b * c};
	ll g = __gcd(p.F, p.S);
	p.F /= g;
	p.S /= g;

	vector<ll> vec = {p.F, p.S};
	if (nums.find(vec) == nums.end())
		nums[vec] = nums.size();
	return nums[vec];
}

void add(int u, int v) {
	while (e.size() < max(u, v) + 1)
		e.push_back({});
	e[u].insert(v);
	e[v].insert(u);
}

int cnt = 0;
void work(vector<int> l) {
	int u = num(l[0] + l[1], l[1], l[2], l[3]);
	int v = num(l[0], l[1], l[2] + l[3], l[3]);

	add(u, v);
	inp[{v, u}].push_back(cnt);
	inp[{u, v}].push_back(cnt);
	if (viv)
		cout << cnt << ": " << u << " and " << v << '\n';
	cnt++;
}

vector<int> d;
void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1) {
			DFS(u, c + 1);
		}
	vector<int> p;
	vector<int> kids;
	for (auto u : e[v])
		if (d[u] < d[v]) {
			for (auto pr : inp[{u, v}])
				if (!used[pr])
					p.push_back(pr);
		}
		else {
			for (auto pr : inp[{u, v}])
				if (!used[pr])
					kids.push_back(pr);
		}
	for (auto pr : kids)
		p.push_back(pr);
	while (p.size() > 1) {
		int a = p.back();
		p.pop_back();
		int b = p.back();
		p.pop_back();
		used[a] = used[b] = true;
		ans.push_back({a, b});
	}
}

void work_tree() {
	int n = nums.size();
	d.resize(n, -1);
	for (int i = 0; i < n; i++)
		if (d[i] == -1)
			DFS(i);	
}

void print() {
	cout << ans.size() << '\n';
	for (auto p : ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
}

void solve() {
	cin >> n;
	v.resize(n);
	used.resize(n, false);
	for (auto &l : v)
		read(l), work(l);

	work_tree();
	print();
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